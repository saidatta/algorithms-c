/**
 * @file linked_list_example.c
 * @brief Example usage of the linked list implementation
 */

#include "data_structures.h"
#include <stdio.h>

int main() {
    // Create a new linked list
    LinkedList* list = linked_list_create();
    if (list == NULL) {
        fprintf(stderr, "Failed to create linked list\n");
        return 1;
    }
    
    printf("Created a new linked list\n");
    
    // Insert elements at the head
    linked_list_insert_head(list, 10);
    linked_list_insert_head(list, 20);
    linked_list_insert_head(list, 30);
    printf("Inserted 3 elements at the head: 30, 20, 10\n");
    
    // Insert elements at the tail
    linked_list_insert_tail(list, 40);
    linked_list_insert_tail(list, 50);
    printf("Inserted 2 elements at the tail: 40, 50\n");
    
    // Insert at a specific position
    linked_list_insert_at(list, 35, 2);
    printf("Inserted 35 at position 2\n");
    
    // Print the list
    printf("Current list (size: %zu): ", linked_list_size(list));
    int value;
    for (size_t i = 0; i < linked_list_size(list); i++) {
        if (linked_list_get_at(list, i, &value)) {
            printf("%d ", value);
        }
    }
    printf("\n");
    
    // Remove elements
    linked_list_remove_head(list);
    printf("Removed head element\n");
    
    linked_list_remove_tail(list);
    printf("Removed tail element\n");
    
    linked_list_remove_at(list, 2);
    printf("Removed element at position 2\n");
    
    // Print the final list
    printf("Final list (size: %zu): ", linked_list_size(list));
    for (size_t i = 0; i < linked_list_size(list); i++) {
        if (linked_list_get_at(list, i, &value)) {
            printf("%d ", value);
        }
    }
    printf("\n");
    
    // Destroy the linked list
    linked_list_destroy(list);
    printf("Destroyed the linked list\n");
    
    return 0;
}