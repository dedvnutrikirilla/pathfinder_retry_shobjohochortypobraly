#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size <= 0) {
        free(ptr);
        ptr = NULL;
        return NULL;
    }

    if (!ptr) {
        return malloc(size);
    }

    size_t len = malloc_size(ptr);
    //size_t len = malloc_usable_size(ptr);

    if (len > size) {
        size = len;
    }

    void *new_ptr = (void *)malloc(size);
    new_ptr = mx_memmove(new_ptr, ptr, size);

    free(ptr);
    ptr = NULL;

    return new_ptr;
}
