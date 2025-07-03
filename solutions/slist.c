#include<stdlib.h>
#include "slist.h"

SNode* add_node(SNode *head, int value) {
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    if (!new_node) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = head;
    return new_node;  // Nouveau head
}
int count_nodes(SNode *head) {
    int count = 0;
    SNode *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void free_list(SNode *head) {
    SNode *current = head;
    while (current != NULL) {
        SNode *temp = current;
        current = current->next;
        free(temp);
    }
}
