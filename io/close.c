// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int cl = syscall(3, fd);
    if (cl < 0) {
    	errno = -cl;
		return -1;
    }
	return cl;
}
