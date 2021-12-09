#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int head = 0;
	int end = size - 1;
	int index;

	while (head <= end) {
		index = (head + end) / 2;
		(*count)++;
		
		if (mx_strcmp(arr[index], s) > 0) {
            end = index - 1;
        }
		else if (mx_strcmp(arr[index], s) < 0) {
            head = index + 1;
        }	
		else {
			return index;
        }
	}

	*count = 0;
	return -1;
}
