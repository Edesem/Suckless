/* See LICENSE file for copyright and license details. */
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "../util.h"

const char *
gid(void)
{
	return bprintf("%d", getgid());
}

const char *
username(void)
{
	struct passwd *pw;

	if (!(pw = getpwuid(geteuid()))) {
		warn("getpwuid '%d':", geteuid());
		return NULL;
	}

	return bprintf("%s", pw->pw_name);
}

const char *
uid(void)
{
	return bprintf("%d", geteuid());
}
