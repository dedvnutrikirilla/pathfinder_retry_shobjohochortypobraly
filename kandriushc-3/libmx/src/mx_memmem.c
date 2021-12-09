#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const unsigned char *big_s = (const unsigned char *)big;

    for(size_t i = 0; (i + little_len) < big_len; i++) {
        if (mx_memcmp((const void *)(big_s + i), little, (little_len - 1)) == 0) {
            return (void *)(big_s + i);
        }
    }

    return NULL;
}
