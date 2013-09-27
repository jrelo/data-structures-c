#include <stdlib.h>
#include <stdio.h>

#include "doubly_linked_list.h"

doubly_linked_list_node_t *create_doubly_linked_list_node(void)
{
	doubly_linked_list_node_t *list = calloc(1, sizeof(doubly_linked_list_node_t));
	
	return list;
}

void delete_doubly_linked_list_node(doubly_linked_list_node_t *node)
{
    free(node);
}

void push_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node)
{
    
}

void pop_d(doubly_linked_list_node_t *list)
{
    
}

void insert_node_after_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *new_node, doubly_linked_list_node_t *node)
{
    
}

void insert_node_before_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *new_node, doubly_linked_list_node_t *node)
{
    
}

void remove_node_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node)
{
    
}

doubly_linked_list_node_t * insert_node_beginning_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node)
{
    return NULL;
}

doubly_linked_list_node_t * remove_node_beginning_d(doubly_linked_list_node_t *list)
{
    return NULL;
}

bool contains_value_d(doubly_linked_list_node_t *list, int value)
{
    return false;
}

doubly_linked_list_node_t * node_for_value_d(doubly_linked_list_node_t *list, int value)
{
    return NULL;
}

doubly_linked_list_node_t * last_node_for_value_d(doubly_linked_list_node_t *list, int value)
{
    return NULL;
}

void print_list_d(doubly_linked_list_node_t *list)
{
    doubly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        printf("%i (%p)\n", current->value, current);
        
        current = current->next;
    }
    
    printf("\n");
}
