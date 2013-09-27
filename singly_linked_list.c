#include <stdlib.h>
#include <stdio.h>

#include "singly_linked_list.h"

singly_linked_list_node_t *create_singly_linked_list_node(void)
{
	singly_linked_list_node_t *list = calloc(1, sizeof(singly_linked_list_node_t));
	
	return list;
}

void delete_singly_linked_list_node(singly_linked_list_node_t *node)
{
    free(node);
}

void push(singly_linked_list_node_t *list, singly_linked_list_node_t *node)
{
    // Make sure we have a list we can use
    if (list == NULL)
    {
        return;
    }
    
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // If this is the last node, set node to be new end of the list
        if (current->next == NULL)
        {
            current->next = node;
            
            return;
        }
        
        current = current->next;
    }
}

void pop(singly_linked_list_node_t *list)
{
    // Make sure we have a list we can use
	if (list == NULL)
    {
        return;
    }
    
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // If we're at the next-to-the-last node, then we can remove the ending node, which set the
        // current node as the last node
        if (current->next->next == NULL)
        {
            current->next = NULL;
            
            return;
        }
        
        current = current->next;
    }
}

void insert_node_after(singly_linked_list_node_t *list, singly_linked_list_node_t *new_node, singly_linked_list_node_t *node)
{
    // Make sure we have all the necessary data
	if (list == NULL || node == NULL || new_node == NULL)
    {
        return;
    }
    
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // Found the node we were looking for. Inser new_node right after it.
        if (current == node)
        {
            singly_linked_list_node_t *previous = current->next;
            current->next = new_node;
            new_node->next = previous;
            
            return;
        }
        
        current = current->next;
    }
}

void remove_node(singly_linked_list_node_t *list, singly_linked_list_node_t *node)
{
    // Make sure we have all the necessary data
	if (list == NULL || node == NULL)
    {
        return;
    }
    
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // Found the node we need to remove, just remove and setup the next pointer
        if (current->next == node)
        {
            current->next = current->next->next;
            
            return;
        }
        
        current = current->next;
    }
}

singly_linked_list_node_t * insert_beginning(singly_linked_list_node_t *list, singly_linked_list_node_t *node)
{
    // Make sure we have a valid list, if not, don't do anything.
	if (list == NULL)
    {
        return list;
    }
    
    // Simply put node at the beginning
    node->next = list;
    
    return node;
}

singly_linked_list_node_t * remove_beginning(singly_linked_list_node_t *list)
{
    // Make sure we have a valid list, if not don't do anything.
	if (list == NULL)
    {
        return list;
    }
    
    return list->next;
}

bool contains_value(singly_linked_list_node_t *list, int value)
{
    // Return an appropriate value if the list is not valid
    if (list == NULL)
    {
        return false;
    }
    
	bool result = false;
	
	singly_linked_list_node_t *current = list;
	
	while(current != NULL)
	{
        // We found a node whose value matches the one we want. Break out of the loop and return.
		if (current->value == value)
		{
			result = true;
			break;
		}
		
		current = current->next;
	}
	
	return result;
}

singly_linked_list_node_t * node_for_value(singly_linked_list_node_t *list, int value)
{
    // Make sure the list is valid
    if (list == NULL)
    {
        return list;
    }
    
    singly_linked_list_node_t *result = NULL;
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // Found the node we wanted. Break out of the loop and return.
        if (current->value == value)
        {
            result = current;
            break;
        }
        
        current = current->next;
    }
    
    return result;
}

singly_linked_list_node_t * last_node_for_value(singly_linked_list_node_t *list, int value)
{
    // Make sure the list is valid
    if (list == NULL)
    {
        return list;
    }
    
    singly_linked_list_node_t *result = NULL;
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        // Found another node whose value matches the one we want. Mark this new one as the one we
        // want.
        if (current->value == value)
        {
            result = current;
        }
        
        current = current->next;
    }
    
    return result;
}

void print_list(singly_linked_list_node_t *list)
{
    singly_linked_list_node_t *current = list;
    
    while (current != NULL)
    {
        printf("%i (%p)\n", current->value, current);
        
        current = current->next;
    }
    
    printf("\n");
}