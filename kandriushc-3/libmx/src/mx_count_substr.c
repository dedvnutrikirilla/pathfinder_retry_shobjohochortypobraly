#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !*str) {
        return -1;
    }
    else if (!sub || !*sub) {
        return -1;
    }
    
    int len_sub = mx_strlen(sub);
    int len_str = mx_strlen(str);
    int n = 0;

    if (len_sub > len_str) {
        return 0;
    }

    while(*str) {
        if(mx_strncmp(str, sub, len_sub) == 0) {
            n++;
        }
        str++;
    }

    return n;   
}
