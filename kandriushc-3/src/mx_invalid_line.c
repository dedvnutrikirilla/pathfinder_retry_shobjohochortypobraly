#include "../inc/path.h"

void mx_invalid_line(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i));
    mx_printerr(" is not valid\n");
}
