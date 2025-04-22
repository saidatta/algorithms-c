/**
 * @file linked_list.h
 * @brief Singly Linked List implementation in C
 */

#ifndef ALGORITHMS_C_LINKED_LIST_H
#define ALGORITHMS_C_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Node structure for the linked list
 */
typedef struct Node {
    int data;              /**< Data stored in the node */
    struct Node* next;     /**< Pointer to the next node */
} Node;

/**
 * @brief Linked List structure
 */
typedef struct {
    Node* head;            /**< Pointer to the head node */
    size_t size;           /**< Size of the linked list */
} LinkedList;

/**
 * @brief Create a new linked list
 * @return A pointer to the newly created linked list
 */
LinkedList* linked_list_create();

/**
 * @brief Free all memory used by the linked list
 * @param list Pointer to the linked list to free
 */
void linked_list_destroy(LinkedList* list);

/**
 * @brief Insert a new node with the given data at the beginning of the list
 * @param list Pointer to the linked list
 * @param data Data to be inserted
 * @return true if insertion was successful, false otherwise
 */
bool linked_list_insert_head(LinkedList* list, int data);

/**
 * @brief Insert a new node with the given data at the end of the list
 * @param list Pointer to the linked list
 * @param data Data to be inserted
 * @return true if insertion was successful, false otherwise
 */
bool linked_list_insert_tail(LinkedList* list, int data);

/**
 * @brief Insert a new node with the given data at the specified position
 * @param list Pointer to the linked list
 * @param data Data to be inserted
 * @param position Position at which to insert (0-based index)
 * @return true if insertion was successful, false otherwise
 */
bool linked_list_insert_at(LinkedList* list, int data, size_t position);

/**
 * @brief Remove the node at the beginning of the list
 * @param list Pointer to the linked list
 * @return true if removal was successful, false otherwise
 */
bool linked_list_remove_head(LinkedList* list);

/**
 * @brief Remove the node at the end of the list
 * @param list Pointer to the linked list
 * @return true if removal was successful, false otherwise
 */
bool linked_list_remove_tail(LinkedList* list);

/**
 * @brief Remove the node at the specified position
 * @param list Pointer to the linked list
 * @param position Position from which to remove (0-based index)
 * @return true if removal was successful, false otherwise
 */
bool linked_list_remove_at(LinkedList* list, size_t position);

/**
 * @brief Get the data at the specified position
 * @param list Pointer to the linked list
 * @param position Position from which to get data (0-based index)
 * @param data Pointer to store the retrieved data
 * @return true if data was successfully retrieved, false otherwise
 */
bool linked_list_get_at(const LinkedList* list, size_t position, int* data);

/**
 * @brief Check if the linked list is empty
 * @param list Pointer to the linked list
 * @return true if the list is empty, false otherwise
 */
bool linked_list_is_empty(const LinkedList* list);

/**
 * @brief Get the size of the linked list
 * @param list Pointer to the linked list
 * @return The size of the linked list
 */
size_t linked_list_size(const LinkedList* list);

#endif // ALGORITHMS_C_LINKED_LIST_H