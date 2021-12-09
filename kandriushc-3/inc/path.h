#ifndef PATH_HEADER_H
#define PATH_HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../libmx/inc/libmx.h"

// vvv delete this vvv
//#include <stdio.h>
// ^^^ delete this ^^^

typedef struct s_edge {
    char* epoint_name_1;
    char* epoint_name_2;
    
    int elength_init;
    int position;
}           t_edge;

typedef struct s_path {
    int *reverse_path;
    int *reverse_distance;
    int reverse_counter;
    int current_id;
}           t_path;

///
void mx_pfinder(int island_count, char **island_names, int starter, int **matrix, t_edge **edge_arr, int edge_count);
int **mx_adj_matrix(int island_count, int edge_count, char **island_names, t_edge **edge_arr);
void mx_path_split (t_path **path_arr, int number_paths, int island_count, int currenter, int father);
void mx_printerr(const char *s);
void mx_invalid_line(int i);
void mx_free_edge(t_edge ***edge_arr, int ecount);
void mx_free_name(char **names_arr, int ncount);
void mx_free_matrix(int **matrix, int size);
void mx_free_path(t_path ***path_arr, int island_count);
void mx_free_strings(char *string_file, char **string_arr);
bool mx_isdigit(int c);
bool mx_isalpha (int c);
int mx_count_words(const char *str, char c);
int mx_atoi(const char *str);
///

#endif
