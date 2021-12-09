#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b)) {
    if(list == NULL) { 
        return list;
    }

    t_list *last = NULL, *current;
    bool flag = true;

    while(flag) {
        flag = false;

        current = list;
        while (current->next != last) {
            if ((*cmp)(current->data, current->next->data)) {
                void *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                flag = true;
            }
            current = current->next;
        }
        last = current;
    }

    return list;
}
