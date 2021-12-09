#include "../inc/libmx.h"

void mx_pop_index(t_list **list, int index) {
    if (*list == NULL || list == NULL) {return;}
    t_list *prev_node, *temp = *list;

    if(index <= 0 || temp->next == NULL) {
        mx_pop_front(list);
        return;
    }

    int size = 0;
    while (temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    temp = *list;

    if(index > size) {
        mx_pop_back(list);
        return;
    }
    else {
        size = 0;

        while (size <= index) {
            if (size == index) {
                prev_node->next = temp->next;
                free(temp);
                return;
            }
            prev_node = temp;
            temp = temp->next;
            size++;
        }
    }
}
