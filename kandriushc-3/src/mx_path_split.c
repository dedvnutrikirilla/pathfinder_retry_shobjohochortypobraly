#include "../inc/path.h"

void mx_path_split (t_path **path_arr, int number_paths, int island_count, int currenter, int father) {
    path_arr[number_paths] = (t_path *)malloc(sizeof(t_path));
    path_arr[number_paths]->reverse_path = (int *)malloc(sizeof(int) * island_count);
    path_arr[number_paths]->reverse_distance = (int *)malloc(sizeof(int) * island_count);
    path_arr[number_paths]->reverse_counter = path_arr[father]->reverse_counter;
    path_arr[number_paths]->current_id = currenter;

    for(int i = 0; i < island_count; i++) {
        path_arr[number_paths]->reverse_path[i] = path_arr[father]->reverse_path[i];
        path_arr[number_paths]->reverse_distance[i] = path_arr[father]->reverse_distance[i];
    }
}
