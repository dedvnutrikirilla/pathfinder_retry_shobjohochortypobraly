#include "../inc/path.h"

int mx_atoi(const char *str) {
    int len = 0;
    int sign = 0;
    int ato = 0;

    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if ((str[i] == '-' || str[i] == '+') 
        && sign == 0 
        && ato == 0) {
            if(str[i] == '-') {
                sign--;
            }
            else if(str[i] == '+') {
                sign++;
            }
        }
        else if (mx_isdigit(str[i])) {
            ato *= 10;
            ato += str[i] - 48;
        }
        else {
            break;
        }
    }

    for (int i = 1; i < len; i++) {
        if (!mx_isdigit(str[i])) {
            return 0;
        } 
    }

    if(sign < 0) {
        ato *= -1;
    }

    return ato;
}
