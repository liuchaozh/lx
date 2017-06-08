#ifndef NGX_CONFIG_H
#define NGX_CONFIG_H

#if NGX_WIN32
#else
#include <ngx_posix_config.h>
#endif

namespace ngx {

using int_t = intptr_t;
using uint_t = uintptr_t;
using flag_t = intptr_t;

}

#endif // !NGX_CONFIG_H
