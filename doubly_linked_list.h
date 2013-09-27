#include <stdbool.h>

typedef struct doubly_linked_list_node_t
{
    int value;
    
    struct doubly_linked_list_node_t *next;
    struct doubly_linked_list_node_t *previous;
}
doubly_linked_list_node_t;

doubly_linked_list_node_t *create_doubly_linked_list_node(void);
void delete_doubly_linked_list_node(doubly_linked_list_node_t *node);

void push_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node);
void pop_d(doubly_linked_list_node_t *list);

void insert_node_after_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *new_node, doubly_linked_list_node_t *node);
void insert_node_before_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *new_node, doubly_linked_list_node_t *node);

void remove_node_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node);

doubly_linked_list_node_t * insert_node_beginning_d(doubly_linked_list_node_t *list, doubly_linked_list_node_t *node);
doubly_linked_list_node_t * remove_node_beginning_d(doubly_linked_list_node_t *list);

bool contains_value_d(doubly_linked_list_node_t *list, int value);

doubly_linked_list_node_t * node_for_value_d(doubly_linked_list_node_t *list, int value);
doubly_linked_list_node_t * last_node_for_value_d(doubly_linked_list_node_t *list, int value);

void print_list_d(doubly_linked_list_node_t *list);
