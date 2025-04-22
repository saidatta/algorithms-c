/**
 * @file linked_list.c
 * @brief Implementation of the linked list functions
 */

#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

LinkedList* linked_list_create() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL; // Memory allocation failed
    }
    
    list->head = NULL;
    list->size = 0;
    
    return list;
}

void linked_list_destroy(LinkedList* list) {
    if (list == NULL) {
        return;
    }
    
    Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(list);
}

bool linked_list_insert_head(LinkedList* list, int data) {
    if (list == NULL) {
        return false;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return false; // Memory allocation failed
    }
    
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    
    return true;
}

bool linked_list_insert_tail(LinkedList* list, int data) {
    if (list == NULL) {
        return false;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return false; // Memory allocation failed
    }
    
    new_node->data = data;
    new_node->next = NULL;
    
    if (list->head == NULL) {
        // List is empty, new node becomes the head
        list->head = new_node;
    } else {
        // Find the last node
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    list->size++;
    return true;
}

bool linked_list_insert_at(LinkedList* list, int data, size_t position) {
    if (list == NULL || position > list->size) {
        return false;
    }
    
    if (position == 0) {
        return linked_list_insert_head(list, data);
    }
    
    if (position == list->size) {
        return linked_list_insert_tail(list, data);
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return false; // Memory allocation failed
    }
    
    new_node->data = data;
    
    // Find the node before the position
    Node* current = list->head;
    for (size_t i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
    
    return true;
}

bool linked_list_remove_head(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    
    Node* to_remove = list->head;
    list->head = to_remove->next;
    free(to_remove);
    list->size--;
    
    return true;
}

bool linked_list_remove_tail(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    
    if (list->head->next == NULL) {
        // Only one node in the list
        free(list->head);
        list->head = NULL;
        list->size = 0;
        return true;
    }
    
    // Find the second-to-last node
    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    list->size--;
    
    return true;
}

bool linked_list_remove_at(LinkedList* list, size_t position) {
    if (list == NULL || list->head == NULL || position >= list->size) {
        return false;
    }
    
    if (position == 0) {
        return linked_list_remove_head(list);
    }
    
    if (position == list->size - 1) {
        return linked_list_remove_tail(list);
    }
    
    // Find the node before the one to remove
    Node* current = list->head;
    for (size_t i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    Node* to_remove = current->next;
    current->next = to_remove->next;
    free(to_remove);
    list->size--;
    
    return true;
}

bool linked_list_get_at(const LinkedList* list, size_t position, int* data) {
    if (list == NULL || list->head == NULL || position >= list->size || data == NULL) {
        return false;
    }
    
    Node* current = list->head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    
    *data = current->data;
    return true;
}

bool linked_list_is_empty(const LinkedList* list) {
    return (list == NULL || list->head == NULL);
}

size_t linked_list_size(const LinkedList* list) {
    return (list != NULL) ? list->size : 0;
}