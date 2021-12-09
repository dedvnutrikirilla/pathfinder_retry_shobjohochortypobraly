#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    int j = 0;
    int length = mx_strlen(str);
    int space_before = 0, space_after = 0;

    while(mx_isspace(str[space_before])) {
        space_before++;
    }
    while(mx_isspace(str[length - space_after - 1])) {
        space_after++;
    }

    if(length - space_before - space_after <= 0) {
        return NULL;
    }

    char *buffer = mx_strnew(length - space_before - space_after);

    for(int i = space_before; i < length - space_after; i++) {
        buffer[j] = str[i];
        j++;
    }

    return (char *)buffer;
}
