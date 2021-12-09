#include "../inc/path.h"

void mx_free_name(char **names_arr, int ncount) {
    for(int i = 0; i < ncount; i++) {
        if (names_arr[i]) {
            free(names_arr[i]);
            names_arr[i] = NULL;
        }
    }
    free(names_arr);
    names_arr = NULL;
}
