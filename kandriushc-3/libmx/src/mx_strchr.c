#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    if (*s == c) {
        return (char*)s;
    }
    while (*s++) {
        if (*s == c) {
            return (char*)s;
        }
    }
    
    return NULL;
}
