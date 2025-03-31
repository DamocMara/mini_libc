// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int tr = syscall(76, path, length);
	if (tr < 0) {
		errno = - tr;
		return -1;
	}
	return tr;
}
