#include "../inc/path.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit (-1);
    }

    int file_directory_check;
    int file_length = 0;
	char file_char_check;
    if ((file_directory_check = open(argv[1], O_RDONLY)) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(-1);
    }

    while(read(file_directory_check, &file_char_check, 1)) {
        file_length++;
    }
	close(file_directory_check);

    if (file_length == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(-1);
    }

    char *string_file = mx_file_to_str(argv[1]);
    char **string_arr = mx_strsplit(string_file, '\n');
    
    char **temp = string_arr;
    int string_arr_len = 0;

    while (*temp) {
        temp++;
        string_arr_len++;
    }
    // Count of bridges (edges) is equal to number of strings in file -1
    int edge_count = string_arr_len - 1;
    //
    //printf("NUMBER OF STRINGS: %d\n", string_arr_len);
    //

    // Checking first string, which should be only number of islands
    for (int j = 0; j < mx_strlen(string_arr[0]); j++) {
        if (!mx_isdigit(string_arr[0][j])) {
            mx_printerr("error: line 1 is not valid\n");
            mx_free_strings(string_file, string_arr);
            exit(-1);
        }
    }
    // ^^ Checking first string, which should be only number of islands ^^

    t_edge **edge_arr = (t_edge **)malloc(sizeof(t_edge *) * (edge_count));
    unsigned long total_elength = 0;
    // vv Now other strings vv
    for (int i = 1; i < string_arr_len; i++) {
        int j = 0, n = 0;

        edge_arr[i - 1] = (t_edge *)malloc(sizeof(t_edge));
        edge_arr[i - 1]->epoint_name_1 = NULL;
        edge_arr[i - 1]->epoint_name_2 = NULL;
        if (string_arr[i][j] == '-') {
            mx_invalid_line(i + 1);
            mx_free_edge(&edge_arr, edge_count);
            mx_free_strings(string_file, string_arr);
            exit(-1);
        }
        while (string_arr[i][j] != '-') {
            if(!mx_isalpha(string_arr[i][j])) {
                mx_invalid_line(i + 1);
                mx_free_edge(&edge_arr, edge_count);
                mx_free_strings(string_file, string_arr);
                exit(-1);
            }
            j++;
        }
        edge_arr[i - 1]->epoint_name_1 = mx_strndup(string_arr[i], j);
        j++;

        n = j;
        if (string_arr[i][j] == ',') {
            mx_invalid_line(i + 1);
            mx_free_edge(&edge_arr, edge_count);
            mx_free_strings(string_file, string_arr);
            exit(-1);
        }
        while (string_arr[i][j] != ',') {
            if(!mx_isalpha(string_arr[i][j])) {
                mx_invalid_line(i + 1);
                mx_free_edge(&edge_arr, edge_count);
                mx_free_strings(string_file, string_arr);
                exit(-1);
            }
            j++;
        }
        edge_arr[i - 1]->epoint_name_2 = mx_strndup(string_arr[i] + n, j - n);
        j++;

        n = j;
        if (string_arr[i][j] == '\0') {
            mx_invalid_line(i + 1);
            mx_free_edge(&edge_arr, edge_count);
            mx_free_strings(string_file, string_arr);
            exit(-1);
        }
        while (string_arr[i][j] != '\0') {
            if(!mx_isdigit(string_arr[i][j])) {
                mx_invalid_line(i + 1);
                mx_free_edge(&edge_arr, edge_count);
                mx_free_strings(string_file, string_arr);
                exit(-1);
            }
            j++;
        }

        edge_arr[i - 1]->elength_init = mx_atoi(string_arr[i] + n);
        total_elength += edge_arr[i - 1]->elength_init;

        if(mx_strcmp(edge_arr[i - 1]->epoint_name_1, edge_arr[i - 1]->epoint_name_2) == 0) {
            mx_invalid_line(i + 1);
            mx_free_edge(&edge_arr, edge_count);
            mx_free_strings(string_file, string_arr);
            exit(-1);
        }

        edge_arr[i - 1]->position = i - 1;
    }

    // creating array with island names and counting islands
    int island_count = 0;
    char **island_names = (char **)malloc(sizeof(char *) * ((edge_count) * 2));
    for (int i = 0; i < edge_count * 2; i++) {
        island_names[i] = NULL;
    }
    

    for (int i = 0; i < edge_count; i++) {
        char **temp = island_names;

        bool flag1 = true, flag2 = true;

        while (*temp) {
            if (mx_strcmp(edge_arr[i]->epoint_name_1, *temp) == 0) {
                flag1 = false;
            }
            if (mx_strcmp(edge_arr[i]->epoint_name_2, *temp) == 0) {
                flag2 = false;
            }
            temp++;
        }

        if (flag1) {
            island_names[island_count] = mx_strdup(edge_arr[i]->epoint_name_1);
            island_count++;
        }
        if (flag2) {
            island_names[island_count] = mx_strdup(edge_arr[i]->epoint_name_2);
            island_count++;
        }
    }

    if (island_count != mx_atoi(string_arr[0])) {
        mx_printerr("error: invalid number of islands\n");
        mx_free_name(island_names, edge_count * 2);
        mx_free_edge(&edge_arr, edge_count);
        mx_free_strings(string_file, string_arr);
        exit(-1);
    }

    for (int i = 0; i < edge_count; i++) {
        for (int j = i + 1; j < edge_count; j++) {
            if (((mx_strcmp(edge_arr[i]->epoint_name_1, edge_arr[j]->epoint_name_1) == 0)
            || (mx_strcmp(edge_arr[i]->epoint_name_1,  edge_arr[j]->epoint_name_2) == 0))
            && ((mx_strcmp(edge_arr[i]->epoint_name_2, edge_arr[j]->epoint_name_1) == 0)
            || (mx_strcmp(edge_arr[i]->epoint_name_2, edge_arr[j]->epoint_name_2) == 0))) {
                mx_printerr("error: duplicate bridges\n");
                mx_free_edge(&edge_arr, edge_count);
                mx_free_name(island_names, edge_count * 2);
                mx_free_strings(string_file, string_arr);
                exit(-1);
            }
        }
    }

    if (total_elength >= 2147483647) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_free_edge(&edge_arr, edge_count);
        mx_free_name(island_names, edge_count * 2);
        mx_free_strings(string_file, string_arr);
        exit(-1);
    }

    ///// VVV MAIN CODE VVV
    int **adj_mat = mx_adj_matrix(island_count, edge_count, island_names, edge_arr);
    /*
    for (int i = 0;  i < 1; i++) {
        mx_pfinder(island_count, island_names, i, adj_mat);
    }
    */
    for (int i = 0;  i < island_count; i++) {
        mx_pfinder(island_count, island_names, i, adj_mat, edge_arr, edge_count);
    }

    ///
    mx_free_edge(&edge_arr, edge_count);
    mx_free_name(island_names, edge_count * 2);
    mx_free_matrix(adj_mat, island_count);
    mx_free_strings(string_file, string_arr);
    ///
}
