#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return 0;
}
