#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    int halflen = len/2;

    for (int i = 0; i < halflen; i++) {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
