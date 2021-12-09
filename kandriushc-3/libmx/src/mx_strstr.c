#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);

    for (int i = 0; i < len1; i++) {
        if (mx_strncmp(&s1[i], s2, len2) == 0) {
            return mx_strchr(&s1[i], s1[i]);
        }
    }

    return 0;
}
