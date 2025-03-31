// SPDX-License-Identifier: BSD-3-Clause
#include <errno.h>
#include <sys/mman.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <unistd.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
    if (fd > -1) {
        //Stabilim eroarea de tip descriptor de fișier invalid
        errno = EBADF;
        //Returnam eroare specifică de alocare în mmap
        return MAP_FAILED;
    }
    // Verificare dacă flag-urile necesare sunt setate
    if ((flags & (MAP_SHARED | MAP_PRIVATE)) == 0) {
        //Stabilim eroarea specifica flagurilor invalide
        errno = EINVAL;
        return MAP_FAILED;
    }
    void *mm = (void *)syscall(9, addr, length, prot, flags, fd, offset);
    if ((long)mm == -1) {
		return  NULL;
    }
    return mm;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *mr = (void *)syscall(25, old_address, old_size, new_size, flags);
    if ((long)mr == -1) {
		return NULL;
    }
    return mr;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int mu = syscall(11, addr, length);
    if (mu == -1) {
		return -1;
    }
    return 0;
}
