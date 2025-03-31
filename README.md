Build a minimalistic standard C library implementation for Linux systems (named mini-libc), that can be used as a replacement for the system libc (glibc in Linux).
The goal is to have a minimally functional libc with features such as string management, basic memory support and POSIX file I/O.
The implementation of mini-libc will be freestanding, i.e. it will not use any outside library calls.
It will be implemented on top of the system call interface provided by Linux on an x86_64 architecture.
Any function you require, that is typically part of libc, you will have to implement.
You can reuse functions that you implement in other parts of the mini-libc.
