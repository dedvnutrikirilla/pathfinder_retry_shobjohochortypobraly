#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int len_sub = mx_strlen(sub);
    int len_replace = mx_strlen(str);

    if (!str || !*str
    || !sub|| !*sub
    || !replace || !*replace
    || mx_strlen(str) < len_sub) {
        return NULL;
    }

    int diff = 0;

    diff = len_sub > len_replace ? len_sub - len_replace : len_replace - len_sub;
    int len = mx_strlen(str) + mx_count_substr(str, sub) * diff;
    char *buff = mx_strnew(len);

    for (int i = 0; i < len; i++) {
        if (mx_strncmp(str, sub, len_sub) == 0) {
            str += len_sub;
            for(int j = 0; j < len_replace; j++) {
                buff[i] = replace[j];
                i++;
            }
        }
        else {
            buff[i] = *str;
        }
        str++;
    }

    return buff;
}
