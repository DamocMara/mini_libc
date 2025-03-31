// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
	return (char *)destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	 while (*source != '\0' && len > 0) {
        *destination = *source;
        destination++;
        source++;
        len--;
    }
    while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }
    return (char *)destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	 char *aux = destination;
    while (*aux != '\0') {
        aux++;
    }
    while (*source != '\0') {
        *aux = *source;
        aux++;
        source++;
    }
    *aux = '\0';
	return (char *)destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *aux = destination;
    while (*aux != '\0') {
        aux++;
    }
    while (len > 0 && *source != '\0') {
        *aux = *source;
        aux++;
        source++;
        len--;
    }
    *aux = '\0';
    return (char *)destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && (*str1 == *str2)) {
        str1++;
        str2++;
    }
	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	if (*str1 == '\0' || *str1 < *str2)
		return -1;
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 != '\0' && (*str1 == *str2) && len > 0) {
        str1++;
        str2++;
        len--;
    }
	if (len == 0)
		return 0;
	if (*str1 == '\0')
		return -1;
	return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	 const char *last_occurrence = NULL;
    while (*str != '\0') {
        if (*str == (char)c) {
            last_occurrence = str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return (char *)last_occurrence;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	 size_t len = strlen(needle);
	while(*haystack != '\0'){
		if (strncmp(haystack, needle, len) == 0)
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	size_t len = strlen(needle);
    char *aux = NULL;
    while (*haystack != '\0') {
        if (strncmp(haystack, needle, len) == 0) {
            aux = (char *)haystack;
        }
        haystack++;
    }

    return (char *)aux;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    char *src = (char *)source;
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
    return (char *)destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    char *src = (char *)source;
    if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    return (char *)destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *p1 = (char *)ptr1;
    char *p2 = (char *)ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *ptr = (char *)source;
    for (size_t i = 0; i < num; i++) {
        ptr[i] = (unsigned char)value;
    }
    return (char *)source;
}
