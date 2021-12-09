#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int len = 0;

    while (s1[len] != '\0' || s2[len] != '\0') {
        if (s1[len] > s2[len]) {
            return 1;
        }
        else if (s1[len] < s2[len]) {
            return -1;
        }
        len++;
    }
    return 0;
}
