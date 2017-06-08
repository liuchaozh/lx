#ifndef NGX_CONNECTION_H
#define NGX_CONNECTION_H

#include <ngx_config.h>
#include <ngx_core.h>

#include <string>

namespace ngx {

class Listening
{
public:
	socket_t fd_;
	
	struct sockaddr* sockaddr_;
	socket_t socklen_;
	// �ַ�����ʽ��IP��ַ
	std::string addr_text_;

	// �׽������͡����磬��type��SOCK_STREAMʱ����ʾTCP
	int type_;

	int backlog_;
	// ���ջ�������С
	int rcv_buf_;
	// ���ͻ�������С
	int snd_buf_;

	// TCP���ӳɹ��Ļص�
	ConnectionHandler handler_;

	// �˿ڶ�Ӧ��������
	void* servers_;

	// ��־
	Log log_;
	Log* logp_;

	// ���Ϊ�µ�TCP���Ӵ����ڴ�أ����ڴ�صĳ�ʼ��СӦ����pool_size_
	size_t pool_size_;
	size_t post_accept_buffer_size_;
	/*TCP_DEFER_ACCEPTѡ��ڽ���TCP���ӳɹ��ҽ��յ��û����������ݺ󣬲���Լ����׽��ָ���Ȥ�Ľ��̷����¼�֪ͨ�������ӽ����ɹ������post_accept_timeout�����Ȼû���յ����û����ݣ����ں�ֱ�Ӷ�������*/
	msec_t post_accept_timeout_;

	Listening* previous_;
	Connection* connection_;

	uint_t worker_;

	/*��־λ��Ϊ1���ʾ�ڵ�ǰ���������Ч����ִ��ngx_init_cycleʱ���رռ����˿ڣ�Ϊ0ʱ�������رա��ñ�־λ��ܴ�����Զ�����*/
	unsigned open_��1;
	/*��־λ��Ϊ1��ʾʹ�����е�ngx_cycle_t����ʼ���µ�ngx_cycle_t�ṹ��ʱ�����ر�ԭ�ȴ򿪵ļ����˿ڣ����������������������ã�remainΪ0ʱ����ʾ�����ر������򿪵ļ����˿ڡ��ñ�־λ��ܴ�����Զ����ã��μ�ngx_init_cycle����*/
	unsigned remain_��1;
	/*��־λ��Ϊ1ʱ��ʾ�������õ�ǰngx_listening_t�ṹ���е��׽��֣�Ϊ0ʱ������ʼ���׽��֡��ñ�־λ��ܴ�����Զ�����*/
	unsigned ignore_��1;
	// ��ʾ�Ƿ��Ѿ��󶨡�ʵ����Ŀǰ�ñ�־λû��ʹ��
	unsigned bound_��1; /*�Ѿ���*/
	/*��ʾ��ǰ��������Ƿ�����ǰһ�����̣�������Nginx���򣩣����Ϊ1�����ʾ����ǰһ�����̡�һ��ᱣ��֮ǰ�Ѿ����úõ��׽��֣������ı�*/
	unsigned inherited_��1; /*����ǰһ������*/
	// Ŀǰδʹ��
	unsigned nonblocking_accept_��1;
	// ��־λ��Ϊ1ʱ��ʾ��ǰ�ṹ���Ӧ���׽����Ѿ�����
	unsigned listen_��1;
	// ��ʾ�׽����Ƿ�������Ŀǰ�ñ�־λû������
	unsigned nonblocking_��1;
	// Ŀǰ�ñ�־λû������
	unsigned shared_��1;
	// ��־λ��Ϊ1ʱ��ʾNginx�Ὣ�����ַת��Ϊ�ַ�����ʽ�ĵ�ַ
	unsigned addr_ntop_��1;
	unsigned wildcard_: 1;
};

class Connection
{

};

}

#endif //NGX_CONNECTION_H
