#include "../inc/path.h"

void mx_free_edge(t_edge ***edge_arr, int ecount) {
    for(int i = 0; i < ecount; i++) {
        if ((*edge_arr)[i]) {
            if (malloc_size((*edge_arr)[i])) {
                free((*edge_arr)[i]);
                (*edge_arr)[i] = NULL;
            }
        }
    }
    free(*edge_arr);
    *edge_arr = NULL;
}
