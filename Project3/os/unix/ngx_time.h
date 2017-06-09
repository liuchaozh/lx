#ifndef NGX_TIME_H
#define NGX_TIME_H

#include <ngx_config.h>
#include <ngx_core.h>

namespace ngx {

using msec_t = rbtree_key_t;
using msec_int_t = rbtree_key_int_t;

using tm_t = struct tm;

#define ngx_tm_sec            tm_sec
#define ngx_tm_min            tm_min
#define ngx_tm_hour           tm_hour
#define ngx_tm_mday           tm_mday
#define ngx_tm_mon            tm_mon
#define ngx_tm_year           tm_year
#define ngx_tm_wday           tm_wday
#define ngx_tm_isdst          tm_isdst

#define ngx_tm_sec_t          int
#define ngx_tm_min_t          int
#define ngx_tm_hour_t         int
#define ngx_tm_mday_t         int
#define ngx_tm_mon_t          int
#define ngx_tm_year_t         int
#define ngx_tm_wday_t         int

void TimezoneUpdate(void);
void Localtime(time_t s, tm_t* tm);
void LibcLocaltime(time_t s, struct tm* tm);
void LibcGmtime(time_t s, struct tm* tm);

#define ngx_gettimeofday(tp)  (void) gettimeofday(tp, NULL);
#define ngx_msleep(ms)        (void) usleep(ms * 1000)
#define ngx_sleep(s)          (void) sleep(s)

}

#endif // !NGX_TIME_H
