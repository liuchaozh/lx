#ifndef NGX_CONNECTION_H
#define NGX_CONNECTION_H

#include <ngx_config.h>
#include <ngx_core.h>

namespace ngx {

class Listening
{
public:
	socket_t fd_;
	
	struct sockaddr* sockaddr_;
	socklen_t socklen_;
	// 字符串形式的IP地址
	std::string addr_text_;

	// 套接字类型。例如，当type是SOCK_STREAM时，表示TCP
	int type_;

	int backlog_;
	// 接收缓冲区大小
	int rcv_buf_;
	// 发送缓冲区大小
	int snd_buf_;

	// TCP连接成功的回调
	ConnectionHandler handler_;

	// 端口对应的主机名
	void* servers_;

	// 日志
	Log log_;
	Log* logp_;

	// 如果为新的TCP连接创建内存池，则内存池的初始大小应该是pool_size_
	size_t pool_size_;
	size_t post_accept_buffer_size_;
	/*TCP_DEFER_ACCEPT选项将在建立TCP连接成功且接收到用户的请求数据后，才向对监听套接字感兴趣的进程发送事件通知，而连接建立成功后，如果post_accept_timeout秒后仍然没有收到的用户数据，则内核直接丢弃连接*/
	msec_t post_accept_timeout_;

	Listening* previous_;
	Connection* connection_;

	uint_t worker_;

	/* 标志位，为1则表示在当前监听句柄有效，且执行ngx_init_cycle时不关闭监听端口，为0时则正常关闭。该标志位框架代码会自动设置 */
	unsigned open_:1;
	/*标志位，为1表示使用已有的ngx_cycle_t来初始化新的ngx_cycle_t结构体时，不关闭原先打开的监听端口，这对运行中升级程序很有用，remain为0时，表示正常关闭曾经打开的监听端口。该标志位框架代码会自动设置，参见ngx_init_cycle方法*/
	unsigned remain_:1;
	/*标志位，为1时表示跳过设置当前ngx_listening_t结构体中的套接字，为0时正常初始化套接字。该标志位框架代码会自动设置*/
	unsigned ignore_:1;
	// 表示是否已经绑定。实际上目前该标志位没有使用
	unsigned bound_:1; /*已经绑定*/
	/*表示当前监听句柄是否来自前一个进程（如升级Nginx程序），如果为1，则表示来自前一个进程。一般会保留之前已经设置好的套接字，不做改变*/
	unsigned inherited_:1; /*来自前一个进程*/
	// 目前未使用
	unsigned nonblocking_accept_:1;
	// 标志位，为1时表示当前结构体对应的套接字已经监听
	unsigned listen_:1;
	// 表示套接字是否阻塞，目前该标志位没有意义
	unsigned nonblocking_:1;
	// 目前该标志位没有意义
	unsigned shared_:1;
	// 标志位，为1时表示Nginx会将网络地址转变为字符串形式的地址
	unsigned addr_ntop_:1;
	unsigned wildcard_: 1;
};

class Connection
{
public:
};

}

#endif //NGX_CONNECTION_H
