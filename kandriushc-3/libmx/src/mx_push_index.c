#include "../inc/libmx.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (*list == NULL || list == NULL) {return;}
    t_list *prev_node, *temp = *list;

    if(index <= 0 || temp->next == NULL) {
        mx_push_front(list, data);
        return;
    }

    int size = 0;
    while (temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    temp = *list;

    if(index > size) {
        mx_push_back(list, data);
        return;
    }
    else {
        size = 0;

        while (size <= index) {
            if (size == index) {
                temp = mx_create_node(data);
                temp->next = prev_node->next;
                prev_node->next = temp;
                return;
            }
            prev_node = temp;
            temp = temp->next;
            size++;
        }
    }
}
