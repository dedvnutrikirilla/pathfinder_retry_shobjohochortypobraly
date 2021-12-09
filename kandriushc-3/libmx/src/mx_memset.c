#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    if (!b) {
        return NULL;
    }

    unsigned char *str = (unsigned char *)b; 

    for (size_t i = 0; i < len; i++) {
        str[i] = (unsigned char)c;
    }

    return b;
}
