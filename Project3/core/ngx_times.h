#ifndef NGX_TIMES_H
#define NGX_TIMES_H

#include <ngx_config.h>
#include <ngx_core.h>

namespace ngx {

struct Time
{
	time_t sec_ = 0;
	uint_t msec_ = 0;
	int_t gmtoff_ = 0;
};

void TimeInit(void);
void TimeUpdate(void);

}

#endif // !NGX_TIMES_H
