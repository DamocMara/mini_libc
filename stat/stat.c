// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int st = syscall(4, path, buf);
    if (st < 0) {
    	errno = -st;
		return -1;
    }
	return st;
}
