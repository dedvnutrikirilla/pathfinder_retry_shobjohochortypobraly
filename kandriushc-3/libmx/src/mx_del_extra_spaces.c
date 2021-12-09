#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }
    
    char *trim = mx_strtrim(str);
    int length = mx_strlen(trim);
    char *buffer = mx_strnew(length);
    int j = 0;

    for (int i = 0; i < length; i++) {
        if(mx_isspace(trim[i]) && !mx_isspace(trim[i + 1])) {
            buffer[j] = ' ';
            j++;
        }
        else if (!mx_isspace(trim[i])){
            buffer[j] = trim[i];
            j++;
        }
    }

    mx_strdel(&trim);
    return buffer;
}
