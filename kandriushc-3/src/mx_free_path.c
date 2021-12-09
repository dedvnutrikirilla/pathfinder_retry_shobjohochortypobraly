#include "../inc/path.h"

void mx_free_path(t_path ***path_arr, int island_count) {
    for (int i = 0; i < island_count * island_count; i++) {
        if ((*path_arr)[i]) {
            if (malloc_size((*path_arr)[i]->reverse_path)) {
                free((*path_arr)[i]->reverse_path);
                (*path_arr)[i]->reverse_path = NULL;
            }
            if (malloc_size((*path_arr)[i]->reverse_distance)) {
                free((*path_arr)[i]->reverse_distance);
                (*path_arr)[i]->reverse_distance = NULL;
            }
            free((*path_arr)[i]);
            (*path_arr)[i] = NULL;
        }
    }
    free(*path_arr);
    *path_arr = NULL;
}
