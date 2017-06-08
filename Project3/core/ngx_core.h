#ifndef NGX_CORE_H
#define NGX_CORE_H

#include <ngx_connection.h>
#include <ngx_log.h>
#include <ngx_rbtree.h>
#include <ngx_socket.h>
#include <ngx_time.h>

#include <functional>

namespace ngx {

using ConnectionHandler = std::function<void(Connection*)>;

}

#endif // !NGX_CORE_H
