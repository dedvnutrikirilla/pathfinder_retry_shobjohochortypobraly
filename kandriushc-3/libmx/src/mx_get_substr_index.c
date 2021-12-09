#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !*str) {
        return -2;
    }
    else if (!sub || !*sub) {
        return -2;
    }
    
    int len_sub = mx_strlen(sub);
    int len_str = mx_strlen(str);
    
    for (int i = 0; i < len_str; i++) {
        if(mx_strncmp(str, sub, len_sub) == 0) {
            return i;
        }
        str++;
    }

    return -1;
}
