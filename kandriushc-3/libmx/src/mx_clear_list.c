#include "../inc/libmx.h"

void mx_clear_list(t_list **list) {
    if(list == NULL) {return;}

    t_list *current = *list, *temp = NULL;

    while(current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    *list = NULL;

    return;
}
