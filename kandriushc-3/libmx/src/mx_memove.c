#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *temple = (unsigned char *)malloc(len * sizeof(unsigned char *));
    
    temple = mx_memcpy(temple, src, len);
    dst = mx_memcpy(dst, temple, len);
    free(temple);
    temple = NULL;

    return dst;
    //return mx_memcpy(dst, src, len);
}
