/**
 * @file test_linked_list.c
 * @brief Test suite for the linked list implementation
 */

#include "linked_list.h"
#include <stdio.h>
#include <assert.h>

// Test linked list creation and destruction
void test_create_destroy() {
    LinkedList* list = linked_list_create();
    assert(list != NULL);
    assert(linked_list_is_empty(list));
    assert(linked_list_size(list) == 0);
    linked_list_destroy(list);
    printf("Test create_destroy: PASSED\n");
}

// Test insertion at head
void test_insert_head() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_head(list, 10));
    assert(!linked_list_is_empty(list));
    assert(linked_list_size(list) == 1);
    
    int value;
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 10);
    
    assert(linked_list_insert_head(list, 20));
    assert(linked_list_size(list) == 2);
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 20);
    
    linked_list_destroy(list);
    printf("Test insert_head: PASSED\n");
}

// Test insertion at tail
void test_insert_tail() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_tail(list, 10));
    assert(!linked_list_is_empty(list));
    assert(linked_list_size(list) == 1);
    
    int value;
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 10);
    
    assert(linked_list_insert_tail(list, 20));
    assert(linked_list_size(list) == 2);
    assert(linked_list_get_at(list, 1, &value));
    assert(value == 20);
    
    linked_list_destroy(list);
    printf("Test insert_tail: PASSED\n");
}

// Test insertion at position
void test_insert_at() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_tail(list, 10));
    assert(linked_list_insert_tail(list, 30));
    assert(linked_list_insert_at(list, 20, 1));
    assert(linked_list_size(list) == 3);
    
    int value;
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 10);
    assert(linked_list_get_at(list, 1, &value));
    assert(value == 20);
    assert(linked_list_get_at(list, 2, &value));
    assert(value == 30);
    
    linked_list_destroy(list);
    printf("Test insert_at: PASSED\n");
}

// Test removal from head
void test_remove_head() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_tail(list, 10));
    assert(linked_list_insert_tail(list, 20));
    assert(linked_list_insert_tail(list, 30));
    
    assert(linked_list_remove_head(list));
    assert(linked_list_size(list) == 2);
    
    int value;
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 20);
    
    linked_list_destroy(list);
    printf("Test remove_head: PASSED\n");
}

// Test removal from tail
void test_remove_tail() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_tail(list, 10));
    assert(linked_list_insert_tail(list, 20));
    assert(linked_list_insert_tail(list, 30));
    
    assert(linked_list_remove_tail(list));
    assert(linked_list_size(list) == 2);
    
    int value;
    assert(linked_list_get_at(list, 1, &value));
    assert(value == 20);
    
    linked_list_destroy(list);
    printf("Test remove_tail: PASSED\n");
}

// Test removal from position
void test_remove_at() {
    LinkedList* list = linked_list_create();
    assert(linked_list_insert_tail(list, 10));
    assert(linked_list_insert_tail(list, 20));
    assert(linked_list_insert_tail(list, 30));
    
    assert(linked_list_remove_at(list, 1));
    assert(linked_list_size(list) == 2);
    
    int value;
    assert(linked_list_get_at(list, 0, &value));
    assert(value == 10);
    assert(linked_list_get_at(list, 1, &value));
    assert(value == 30);
    
    linked_list_destroy(list);
    printf("Test remove_at: PASSED\n");
}

int main() {
    printf("Running linked list tests...\n");
    
    test_create_destroy();
    test_insert_head();
    test_insert_tail();
    test_insert_at();
    test_remove_head();
    test_remove_tail();
    test_remove_at();
    
    printf("All tests PASSED!\n");
    return 0;
}