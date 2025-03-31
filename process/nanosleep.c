#define _GNU_SOURCE
#include <unistd.h>
#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    return syscall(35, req, rem);
}
