#include <stdio.h>

#include "dynamic_array.h"
#include "singly_linked_list.h"

void test_dynamic_array();
void test_singly_linked_list();

int main(int argc, char **argv)
{
	test_singly_linked_list();
	
	return 0;
}

void test_singly_linked_list()
{
    singly_linked_list_node_t l = create_singly_linked_list_node();
    singly_linked_list_node_t *list = &l;
    
    printf("New list created.\n");
    print_list(list);
    
    list->value = 1;
    
    printf("Set first node value.\n");
    print_list(list);
    
    singly_linked_list_node_t n2 = create_singly_linked_list_node();
    singly_linked_list_node_t *node2 = &n2;
    node2->value = 2;
    
    list->next = node2;
    
    printf("Set second node.\n");
    print_list(list);
    
    printf("list contains 2?: %s\n", contains_value(list, 2) ? "Yes" : "No");
    printf("list contains 3?: %s\n\n", contains_value(list, 3) ? "Yes" : "No");
    
    singly_linked_list_node_t n3 = create_singly_linked_list_node();
    singly_linked_list_node_t *node3 = &n3;
    node3->value = 3;
    
    printf("Push node3 onto list:\n");
    push(list, node3);
    
    print_list(list);
    
    printf("Pop node3 from the list:\n");
    pop(list);
    print_list(list);
    
    printf("Pop node2 from the list:\n");
    pop(list);
    print_list(list);
    
    printf("Push node3, then node2 onto the list:\n");
    push(list, node3);
    push(list, node2);
    print_list(list);
    
    printf("Create node4 and insert at the beginning:\n");
    singly_linked_list_node_t n4 = create_singly_linked_list_node();
    singly_linked_list_node_t *node4 = &n4;
    node4->value = 4;
    list = insert_beginning(list, node4);
    print_list(list);
    
    printf("Remove the starting node:\n");
    list = remove_beginning(list);
    print_list(list);
    
    printf("Create two new nodes and add them and node4 to the list:\n");
    singly_linked_list_node_t n5 = create_singly_linked_list_node();
    singly_linked_list_node_t *node5 = &n5;
    node5->value = 5;
    
    singly_linked_list_node_t n4prime = create_singly_linked_list_node();
    singly_linked_list_node_t *node4prime = &n4prime;
    node4prime->value = 4;
    
    node4->next = NULL;
    
    push(list, node4);
    push(list, node5);
    push(list, node4prime);
    
    print_list(list);
    
    printf("Find the first node with value of 6\n");
    singly_linked_list_node_t *result = node_for_value(list, 6);
    
    if (result != NULL)
    {
        printf("value: %i (%p) should be %i (%p)\n\n", result->value, result, 0, NULL);
    }
    else
    {
        printf("Not found.\n\n");
    }
    
    printf("Find the first node with value of 5\n");
    result = node_for_value(list, 5);
    printf("value: %i (%p) should be %i (%p)\n\n", result->value, result, node5->value,&node5);
    
    printf("Find the first node with value of 4\n");
    result = node_for_value(list, 4);
    printf("value: %i (%p) should be %i (%p)\n\n", result->value, result, node4->value, node4);
    
    printf("Find the last node with value of 4\n");
    result = last_node_for_value(list, 4);
    printf("value: %i (%p) should be %i (%p)\n\n", result->value, result, node4prime->value, node4prime);
    
    printf("\n");

    printf("Create node6 and add it after node5\n");
    singly_linked_list_node_t n6 = create_singly_linked_list_node();
    singly_linked_list_node_t *node6 = &n6;
    node6->value = 6;
    insert_node_after(list, node6, node5);
    print_list(list);
    
    printf("Remove node4 from the list\n");
    remove_node(list, node4);
    print_list(list);
}

void test_dynamic_array()
{
	dynamic_array_t array = create_array();
	
	printf("Creating brand new array:\n");
	print_array(array);
	
	set(&array, 2, 58);
	set(&array, 6, 43);
	printf("Setting a couple of values:\n");
	print_array(array);
	
	set(&array, 10, 200);
	printf("Setting index '10' to '200':\n");
	print_array(array);
	
	insert(&array, 3, 69);	
	printf("Inserting '69' at index '3':\n");
	print_array(array);
	
	printf("Index 2: %i\n", get(array, 2));
	printf("Index 3: %i\n", get(array, 3));
	printf("Index 7: %i\n\n", get(array, 7));
	
	delete(&array, 6);
	printf("Deleting index '6':\n");
	print_array(array);
	
	insert(&array, 5, 55);
	printf("Inserting '55' at index '5':\n");
	print_array(array);
	
	insert(&array, 10, 100);
	printf("Inserting '100' at index '10':\n");
	print_array(array);
	
	set(&array, 8, 45);
	printf("Setting index '8' to '45':\n");
	print_array(array);
	
	set(&array, 15, 32);
	printf("Setting index '15' to '32':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	insert(&array, 8, 1);
	printf("Inserting '1' at index '8':\n");
	print_array(array);
}