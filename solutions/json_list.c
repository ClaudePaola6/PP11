// solutions/json_list.c
#include "json_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

JObject* parse_json(const char *filename) {
    json_error_t error;
    json_t *root = json_load_file(filename, 0, &error);

    if (!root || !json_is_array(root)) {
        fprintf(stderr, "Erreur lors du chargement de %s: %s\n", filename, error.text);
        return NULL;
    }

    JObject *head = NULL;

    size_t index;
    json_t *value;

    json_array_foreach(root, index, value) {
        if (!json_is_object(value)) continue;

        json_t *jname = json_object_get(value, "name");
        json_t *jage = json_object_get(value, "age");

        if (!json_is_string(jname) || !json_is_integer(jage)) continue;

        JObject *node = malloc(sizeof(JObject));
        if (!node) {
            perror("malloc");
            json_decref(root);
            free_list(head);
            return NULL;
        }

        node->name = strdup(json_string_value(jname));
        node->age = (int)json_integer_value(jage);
        node->next = head;
        head = node;
    }

    json_decref(root);
    return head;
}

void print_list(JObject *head) {
    for (JObject *current = head; current != NULL; current = current->next) {
        printf("Name: %s, Age: %d\n", current->name, current->age);
    }
}

void free_list(JObject *head) {
    while (head) {
        JObject *temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
    }
}
