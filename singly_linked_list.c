#include <stdlib.h>
#include <stdio.h>

#include "singly_linked_list.h"

singly_linked_list_t create_singly_linked_list()
{
	singly_linked_list_t list = { 0, NULL };
	
	return list;
}

void push(singly_linked_list_t *list, singly_linked_list_t node)
{
	
}

void pop(singly_linked_list_t *list)
{
	
}

void insert_after(singly_linked_list_t *node, singly_linked_list_t new_node)
{
	
}

void remove_after(singly_linked_list_t *node)
{
	
}

void insert_beginning(singly_linked_list_t *list, singly_linked_list_t node)
{
	
}

void remove_beginning(singly_linked_list_t *list)
{
	
}

bool contains_value(singly_linked_list_t *list, int value)
{
	bool result = false;
	
	singly_linked_list_t *current = list;
	
	while(current != NULL)
	{
		printf("current->value:      %i\n", current->value);
		printf("current->next NULL?: %i\n", current->next == NULL);
		
		if (current->value == value)
		{
			printf("found.\n");
			
			result = true;
			break;
		}
		
		current = current->next;
	}
	
	return result;
}

singly_linked_list_t *node_for_value(singly_linked_list_t list, int value)
{
	return NULL;
}

singly_linked_list_t *last_node_for_value(singly_linked_list_t list, int value)
{
	return NULL;
}
