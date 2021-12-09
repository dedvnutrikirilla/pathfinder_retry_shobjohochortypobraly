#include "../inc/path.h"

void mx_free_matrix(int **matrix, int size) {
    if (matrix == NULL || *matrix == NULL) {
        return;
    }
        
    for(int i = 0; i < size; i++) {
        if (matrix[i]) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
    }
    free(matrix);
    matrix = NULL;
}
