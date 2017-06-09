#ifndef NGX_CORE_H
#define NGX_CORE_H

#include <time.h>

#include <functional>
#include <list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace ngx {

class Connection;

using ConnectionHandler = std::function<void(Connection*)>;

}

#include <ngx_conf_file.h>
#include <ngx_event.h>
#include <ngx_log.h>
#include <ngx_module.h>
#include <ngx_palloc.h>
#include <ngx_rbtree.h>
#include <ngx_socket.h>
#include <ngx_time.h>
#include <ngx_times.h>
#include <ngx_connection.h>
#include <ngx_cycle.h>

#endif // !NGX_CORE_H
