#ifndef NGX_CYCLE_H
#define NGX_CYCLE_H

#include <ngx_config.h>
#include <ngx_core.h>

namespace ngx {

class ShmZone
{
};

class Cycle
{
public:
	static std::unique_ptr<Cycle> CreateCycle();
	static std::unique_ptr<Cycle> CreateCycle(std::unique_ptr<Cycle> old_cycle);

	Cycle() = default;
	Cycle(const Cycle&) = delete;

public:
	std::vector<std::vector<int>> conf_ctx_;
	Pool* pool_;
	/*日志模块中提供了生成基本ngx_log_t日志对象的功能，这里的log实际上是在还没有执行ngx_init_cycle方法前，
	也就是还没有解析配置前，如果有信息需要输出到日志，就会暂时使用log对象，它会输出到屏幕。在ngx_init_cycle方法执行后，
	将会根据nginx.conf配置文件中的配置项，构造出正确的日志文件，此时会对log重新赋值*/
	Log* log_;
	/*由nginx.conf配置文件读取到日志文件路径后，将开始初始化error_log日志文件，由于log对象还在用于输出日志到屏幕，
	这时会用new_log对象暂时性地替代log日志，待初始化成功后，会用new_log的地址覆盖上面的log指针*/
	Log new_log_;
	uint_t log_use_stderr_;
	/*对于poll、rtsig这样的事件模块，会以有效文件句柄数来预先建立这些ngx_connection_t结构体，
	以加速事件的收集、分发。这时files就会保存所有ngx_connection_t的指针组成的数组，files_n就是指针的总数，
	而文件句柄的值用来访问files数组成员*/
	std::vector<Connection*> files_;
	// 可用连接池
	std::vector<Connection> free_connections_;
	
	std::vector<Module*> modules_;
	uint_t modules_used_;

	/*表示可重复使用连接队列*/
	std::list<Connection> reusable_connections_queue_;

	/*表示监听端口及相关的参数*/
	std::vector<Listening> listening_;

	/*它保存着Nginx所有要操作的目录。如果有目录不存在，则会试图创建，而创建目录失败将会导致Nginx启动失败。
	例如，上传文件的临时目录也在pathes中，如果没有权限创建，则会导致Nginx无法启动*/
	std::vector<std::string> pathes_;

	/*它表示Nginx已经打开的所有文件。事实上，Nginx框架不会向open_files链表中添加文件，
	而是由对此感兴趣的模块向其中添加文件路径名，Nginx框架会在ngx_init_cycle方法中打开这些文件*/
	std::list<OpenFile> open_files_;

	/*每个元素表示一块共享内存*/
	std::list<ShmZone> shared_memory_;

	// 指向当前进程中的所有连接对象
	std::vector<Connection> connections_;

	// 指向当前进程中的所有读事件对象, read_events_.size() == connections_.size()
	std::vector<Event> read_events_;

	// 指向当前进程中的所有写事件对象, write_events_.size() == connections_.size()
	std::vector<Event> write_events_;

	/*旧的ngx_cycle_t对象用于引用上一个ngx_cycle_t对象中的成员。例如ngx_init_cycle方法，在启动初期，
	需要建立一个临时的ngx_cycle_t对象保存一些变量，再调用ngx_init_cycle方法时就可以把旧的ngx_cycle_t对象传进去，
	而这时old_cycle对象就会保存这个前期的ngx_cycle_t对象*/
	Cycle* old_cycle_;

	// 配置文件相对于安装目录的路径名称
	std::string conf_file_;
	/*Nginx处理配置文件时需要特殊处理的在命令行携带的参数，一般是-g选项携带的参数*/
	std::string conf_param_;
	// Nginx配置文件所在目录的路径
	std::string conf_prefix_;
	// Nginx安装目录的路径
	std::string prefix_;
	// 用于进程间同步的文件锁名称
	std::string lock_file_;
	// 使用gethostname系统调用得到的主机名
	std::string hostname_;
};

}

#endif //NGX_CYCLE_H
