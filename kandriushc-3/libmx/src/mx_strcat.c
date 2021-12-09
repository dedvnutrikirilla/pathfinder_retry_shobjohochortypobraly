#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    int j = 0;

    for (int i = len1; i < (len1 + len2); i++) {
        s1[i] = s2[j];
        j++;
    }

    s1[len1 + len2] = '\0';

    return s1;
}
