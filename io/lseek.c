// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int ls = syscall(8, fd, offset, whence);
    if (ls < 0) {
    	errno = -ls;
		return -1;
    }
	return ls;
}
