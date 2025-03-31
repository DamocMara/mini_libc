// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int fs = syscall(5, fd, st);
    if (fs < 0) {
    	errno = -fs;
		return -1;
    }
	return fs;
}
