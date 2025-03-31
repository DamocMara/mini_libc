// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ft = syscall(77, fd, length);
    if (ft < 0) {
    	errno = -ft;
		return -1;
    }
	return ft;
}
