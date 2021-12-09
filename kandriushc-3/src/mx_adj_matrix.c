#include "../inc/path.h"

int **mx_adj_matrix(int island_count, int edge_count, char **island_names, t_edge **edge_arr) {
    int **matrix = (int **)malloc(sizeof(int *) * island_count);
    
    for (int i = 0; i < island_count; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * island_count);
        for (int j = 0; j < island_count; j++) {
            matrix [i][j] = 0;
            for (int e = 0; e < edge_count; e++) {
                if (!edge_arr[e]) continue;
                if ((mx_strcmp(edge_arr[e]->epoint_name_1, island_names[i]) == 0
                && mx_strcmp(edge_arr[e]->epoint_name_2, island_names[j]) == 0)
                || (mx_strcmp(edge_arr[e]->epoint_name_1, island_names[j]) == 0
                && mx_strcmp(edge_arr[e]->epoint_name_2, island_names[i]) == 0)) {
                    matrix[i][j] = edge_arr[e]->elength_init; 
                }
            }
        }
    }

    /*printf("\ndistances:\n");
    for (int i = 0; i < island_count; i++) {
        printf("%s - %s : %d\n", island_names[starter], island_names[i], min_distances[i]);
    }*/

    /////////
    /*printf("\nmatrix:\n");
    for (int i = 0; i < island_count; i++) {
        printf("%d%s  ", i , island_names[i]);
        for (int j = 0; j < island_count; j++) {
            if(matrix[i][j] > 9) {
                printf("%d%s  ", matrix[i][j], island_names[j]);
            }
            else {
                printf("%d%s   ", matrix[i][j], island_names[j]);
            }
        }
        printf("\n");
    }*/
    ////////

    return matrix;
}
