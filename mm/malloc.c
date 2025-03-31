// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <internal/syscall.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
    /* TODO: Implement malloc(). */
	 if (size <= 0) {
        return NULL;
    }
    //Dimensiunea totală de memorie de alocat este spațiul necesar datelor
    //și spațiu dimensiunea memoriei alocate
    size_t total = size + sizeof(size_t);
    void *ptr = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    *(size_t *)ptr = size;
    return (char *)ptr + sizeof(size_t);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
	memset(ptr, 0, nmemb * size);
    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
        return;
    }
    //Calculăm adresa originală alocată înainte de pointerul returnat
    void *original = (void *)((char *)ptr - sizeof(size_t));
    //Recuperăm dimensiunea blocului înainte de pointerul returnat la momentul apelului malloc
    size_t size = *(size_t *)original;
    //Dezalocăm memoria
    munmap(original, size + sizeof(size_t));
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	size_t old = 0;
	void *new = malloc(size);
	if (new == NULL) {
		return NULL;
	}
	if (ptr && old > 0) {
		memcpy(new, ptr, old < size ? old : size);
	}
	return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    if (ptr == NULL) {
        return (void *)syscall(9, NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    }
    //Dacă dimensiunea este 0, este echivalent cu free()
    if (nmemb * size == 0) {
        syscall(11, ptr, 0);
        return NULL;
    }
    //Obținem dimensiunea curentă a blocului și creăm unul nou
    void *new_ptr = (void *)syscall(9, NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_ptr == MAP_FAILED) {
        //errno = ENOMEM;
        return NULL;
    }
    //Copiem datele din blocul original în cel nou, apoi eliberăm vechiul bloc
    size_t old_size = *((size_t *)((char *)ptr - sizeof(size_t)));
    //Se copiază dimensiunea mai mică
    memcpy(new_ptr, ptr, old_size < nmemb * size ? old_size : nmemb * size);
    syscall(11, ptr, old_size + sizeof(size_t));
    return new_ptr;
}
