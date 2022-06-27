/* See LICENSE file for copyright and license details. */
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "../util.h"

const char *
num_files(const char *path)
{
	struct dirent *dp;
	DIR *fd;
	int num;

	if (!(fd = opendir(path))) {
		warn("opendir '%s':", path);
		return NULL;
	}

	num = 0;
	while ((dp = readdir(fd))) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) {
			continue; /* skip self and parent */
		}
		num++;
	}

	closedir(fd);

	return bprintf("%d", num);
}
