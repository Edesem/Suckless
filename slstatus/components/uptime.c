/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "../util.h"

#if defined(CLOCK_BOOTTIME)
	#define UPTIME_FLAG CLOCK_BOOTTIME
#elif defined(CLOCK_UPTIME)
	#define UPTIME_FLAG CLOCK_UPTIME
#else
	#define UPTIME_FLAG CLOCK_MONOTONIC
#endif

const char *
uptime(void)
{
	char warn_buf[256];
	uintmax_t h, m;
	struct timespec uptime;

	if (clock_gettime(UPTIME_FLAG, &uptime) < 0) {
		snprintf(warn_buf, 256, "clock_gettime %d", UPTIME_FLAG);
		warn(warn_buf);
		return NULL;
	}

	h = uptime.tv_sec / 3600;
	m = uptime.tv_sec % 3600 / 60;

	return bprintf("%juh %jum", h, m);
}
