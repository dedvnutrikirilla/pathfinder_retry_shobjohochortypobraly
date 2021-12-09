#include "../inc/libmx.h"
//
void mx_pop_back(t_list **head) {
    if (*head == NULL || head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *last_node = *head, *prev_node = NULL;
    while (last_node->next != NULL) {
        prev_node = last_node;
        last_node = last_node->next;
    }

    prev_node->next = NULL;
    free(last_node);
}
