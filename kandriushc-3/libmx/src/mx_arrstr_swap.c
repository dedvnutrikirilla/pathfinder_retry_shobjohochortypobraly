#include "../inc/libmx.h"

void mx_arrstr_swap(char **arr1, char **arr2) {
    //printf("\n\none swap %s - %s\n", *arr1, *arr2);
    char *temp = *arr2;
	*arr2 = *arr1; 
	*arr1 = temp;
    //printf("after swap %s - %s\n", *arr1, *arr2);
}
