#ifndef MY_TIME_H
#define MY_TIME_H

#include <stddef.h>
#include <sys/types.h>

#ifndef time_t
typedef long time_t;
#endif

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#endif
