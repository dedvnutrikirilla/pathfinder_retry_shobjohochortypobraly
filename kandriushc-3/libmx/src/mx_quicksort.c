#include "../inc/libmx.h"

int mx_quickpartition (char **arr, int left, int right, int *count) {
    char *pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++) {
        if (mx_strcmp(arr[j], pivot) <= 0) {
            count++;
            i++;
            mx_arrstr_swap (&arr[i], &arr[j]);
        }
    }

    mx_arrstr_swap(&arr[i + 1], &arr[right]);

    return i + 1;
}

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;

    if (left >= right) {
        return count;
    }

    int part = mx_quickpartition(arr, left, right, &count);

    count += mx_quicksort(arr, left, part - 1);
    count += mx_quicksort(arr, part + 1, right);
    return count;
}
