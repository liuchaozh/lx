#include <ngx_config.h>
#include <ngx_core.h>

void ngx::TimezoneUpdate(void)
{
#if (NGX_FREEBSD)

	if (getenv("TZ")) {
		return;
	}

	putenv("TZ=UTC");

	tzset();

	unsetenv("TZ");

	tzset();

#elif (NGX_LINUX)
	time_t      s;
	struct tm  *t;
	char        buf[4];

	s = time(0);

	t = localtime(&s);

	strftime(buf, 4, "%H", t);

#endif
}

void ngx::Localtime(time_t s, tm_t* tm)
{
#if (NGX_HAVE_LOCALTIME_R)
	(void)::localtime_r(&s, tm);

#else
	tm_t* t;

	t = ::localtime(&s);
	*tm = *t;

#endif

	tm->ngx_tm_mon++;
	tm->ngx_tm_year += 1900;
}

void ngx::LibcLocaltime(time_t s, tm* tm)
{
#if (NGX_HAVE_LOCALTIME_R)
	(void)::localtime_r(&s, tm);

#else
	struct tm* t;

	t = ::localtime(&s);
	*tm = *t;

#endif
}

void ngx::LibcGmtime(time_t s, tm* tm)
{
#if (NGX_HAVE_LOCALTIME_R)
	(void)::gmtime_r(&s, tm);

#else
	struct tm* t;

	t = ::gmtime(&s);
	*tm = *t;

#endif
}
