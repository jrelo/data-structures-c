#include <stdbool.h>

/**
 * The main data structure for this singly-linked list. Each 
 * `singly_link_list_t` represents a single node in the list.
 */
typedef struct singly_linked_list_node_t
{
    /**
     * The value of the current node.
     */
    int value;
    
    /**
     * A pointer to the next node. If no next node is present or if we are at 
     * the end of the list, this value is `NULL`.
     */
    struct singly_linked_list_node_t *next;
}
singly_linked_list_node_t;

/**
 * Creates a single node that can be used in this singly-linked list.
 *
 * @return A single node with a value of 0 and the next node pointer of `NULL`.
 */
singly_linked_list_node_t *create_singly_linked_list_node(void);

/**
 * Deletes a single node and frees any memory being used by it.
 *
 * @param node A single node to delete and free up.
 */
void delete_singly_linked_list_node(singly_linked_list_node_t *node);

/**
 * Push a node at the end of the linked list represented by `list`. The list of 
 * nodes are traversed until the end of the list is reached. Then `node` is set 
 * as the `next` node of the last node.
 *
 * New nodes are added at the end of the list, which means the list has to 
 * traversed fully, every time a new node is pushed, so the complexity of this 
 * function is O(n)
 *
 * @param list The head node of a singly-linked list.
 * @param node The node to insert at the end of the list.
 *
 * @see pop(singly_linked_list_node_t)
 */
void push(singly_linked_list_node_t *list, singly_linked_list_node_t *node);

/**
 * Pops the last node in the list represented by `list`. The list of nodes are 
 * traversed until the last node is reached. Then the `next` pointer of the 
 * next-to-last node is set to `NULL`, signifying the end of the list.
 *
 * Since the last element in the list needs to be remove, all the elements need 
 * to be traversed. Therefore the complexity fo this function O(n).
 *
 * @param list The head node of a singly-linked list.
 *
 * @see push(singly_linked_list_node_t *, singly_linked_list_node_t *)
 */
void pop(singly_linked_list_node_t *list);

/**
 * Inserts `new_node` after `node` in the `list` singly-linked list. The list 
 * is traversed until `node` is found, at which point `new_node` is inserted 
 * into the list.
 *
 * In the best case we need to insert `new_node` at the beginning so the 
 * complexity of this function would be O(1), essentially constant time. In the
 * worst case we have to insert `new_node` at the end of the list so the 
 * complexity in that case is O(n). In the average case, we need to insert 
 * `new_node` somwhere near the middle of the list so the complexity would be 
 * O(n/2) or simply O(n).
 *
 * @param list The head node that represents a singly-linked list.
 * @param new_node New node to insert into `list`.
 * @param node Node where `new_node` should be inserted as the `next` node.
 */
void insert_node_after(singly_linked_list_node_t *list, singly_linked_list_node_t *new_node, singly_linked_list_node_t *node);

/**
 * Removes the specified node. The list is traversed until `node` is found, 
 * then it is removed.
 *
 * On average we have to look at n/2 nodes, so the complexity of this function 
 * is O(n). The best case is O(1) and the worst case is O(n).
 *
 * @param list The head node that represents a singly-linked list.
 * @param node Node which to remove from the list.
 *
 * @see pop(singly_linked_list_node_t *)
 */
void remove_node(singly_linked_list_node_t *list, singly_linked_list_node_t *node);

/**
 * Inserts `node` at the beginning of the singly-linked list represented by 
 * `list. The final larger list is returned.
 *
 * The list dosn't have to be traversed to achieve this function, so the 
 * complexity is O(1).
 *
 * @param list The head node that represents a singly-linked list.
 * @param node Node which needs to be inserted at the beginning of the list.
 *
 * @return A new, longer list whose new head node is `node`.
 *
 * @see remove_beginning(sinly_linked_list_t *)
 */
singly_linked_list_node_t * insert_beginning(singly_linked_list_node_t *list, singly_linked_list_node_t *node);

/**
 * Remove the head node of the singly-linked list represented by `list`. This 
 * method is similar to calling `pop()` on the first node of the list.
 *
 * The list doesn't have to traversed for this function. Therefore the 
 * complexity is O(1).
 *
 * @param list The head node that represents a singly-linked list.
 *
 * @return A shorter singly-linked list whose first node, the head node, is the 
 * second node of `list` before calling this method.
 *
 * @see inser_beginning(singly_linked_list_node_t *, singly_linked_list_node_t *)
 */
singly_linked_list_node_t * remove_beginning(singly_linked_list_node_t *list);

/**
 * Determines whether `value` exists in the singly-linked list represented by 
 * `list`. Only the first node containing `value is evaluated.
 *
 * On average n/2 nodes have to be checked, therefore the complexity of this 
 * function O(n).
 *
 * @param list The head node that represents a singly-linked list.
 * @param value The value to search
 *
 * @return `true` if `list` contains a node whose value equals `value; `false` 
 * otherwise.
 */
bool contains_value(singly_linked_list_node_t *list, int value);

/**
 * Determines whether a node whose value is equal to `value` exists and returns 
 * that node. Only the first node, relative to the beginnig of the list, is 
 * evaulated and returned. For example, in the following list, the first node 
 * that has value of '4', node at index 3 is returned:
 *
 *        (2, 1, 5, 4, 5, 4)
 *
 * On average n/2 nodes have to be looked at, which makes the complexity of 
 * function to be O(n).
 *
 * @param list Head node of a singly-linked list.
 * @param value The value to search.
 *
 * @return The first node, relative to `list`, whose value is equal to `value`. 
 * If there are multiple nodes whose values are equal to `value, then the first 
 * node relative to `list` is returned.
 *
 * @see last_node_for_value(singly_linked_list_node_t, int)
 */
singly_linked_list_node_t * node_for_value(singly_linked_list_node_t *list, int value);

/**
 * Determines whether a node whose value is equal to `value` exists and returns 
 * that. The last node, relative to the beginning of the list, is returned. For 
 * example, in the following, list, the last node that has a value of '4', the 
 * node at index 5 is returned:
 *
 *        (2, 1, 5, 4, 5, 4)
 *
 * On average n/2 nodes have to be looked at, which makes the complexity of 
 * function to be O(n).
 *
 * @param list Head node of a singly-linked list.
 * @param value The value to search
 *
 * @return The last node, relative to the end of the list, whose value is equal 
 * to `value`. If there are multiple nodes whose values are equal to `value`, 
 * then the last node relative to `list` is returned.
 *
 * @see node_for_value(singly_linked_list_node_t, int)
 */
singly_linked_list_node_t * last_node_for_value(singly_linked_list_node_t *list, int value);

/**
 * Prints the values of all the nodes of `list`. Each element is printed on a 
 * new list and an empty line is printed at the end to distinguish the results 
 * from previous output.
 *
 * @param list Head node of a singly-linked list.
 */
void print_list(singly_linked_list_node_t *list);
