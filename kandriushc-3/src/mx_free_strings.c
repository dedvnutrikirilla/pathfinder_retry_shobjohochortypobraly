#include "../inc/path.h"

void mx_free_strings(char *string_file, char **string_arr) {
    int counter = 0;
    while (string_arr[counter]) {
        free(string_arr[counter]);
        counter++;
    }
    free(string_arr);
    free(string_file);
}
