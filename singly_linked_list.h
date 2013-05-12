#include <stdbool.h>

typedef struct singly_linked_list_t
{
	int value;
	struct singly_linked_list_t *next;
}
singly_linked_list_t;

singly_linked_list_t create_singly_linked_list();

void push(singly_linked_list_t *list, singly_linked_list_t node);

void pop(singly_linked_list_t *list);

void insert_after(singly_linked_list_t *node, singly_linked_list_t new_node);
void remove_after(singly_linked_list_t *node);

void insert_beginning(singly_linked_list_t *list, singly_linked_list_t node);
void remove_beginning(singly_linked_list_t *list);

bool contains_value(singly_linked_list_t *list, int value);

singly_linked_list_t *node_for_value(singly_linked_list_t list, int value);
singly_linked_list_t *last_node_for_value(singly_linked_list_t list, int value);
