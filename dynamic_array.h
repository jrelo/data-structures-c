#include <stdbool.h>

/**
 * Main data structre that will be used as the dynamic array store.
 */
typedef struct
{
	/**
	 * Current size of the array. Indicates how many items can the array 
	 * contain.
	 */
	int size;
	
	/**
	 * Memory storage for the actual array elements.
	 */
	int *elements;
}
dynamic_array_t;

/**
 * Return value used anytime a requested element is not found.
 */
#define NOT_FOUND -1

/**
 * Return value used whenever the specified index is invalid.
 */
#define INVALID_INDEX -2

/**
 * Default number of items `dynamic_array_t` can hold by default if 
 * `create_array` is called with the `size` argument being less than this 
 * value.
 */
#define DEFAULT_SIZE 8

/**
 * Allocates and prepares a dynamic array type with the specified size 
 * argument. If `size` is less than `DEFAULT_SIZE`, the resulting dynamic array
 * will be able to hold `DEFAULT_SIZE` items.
 *
 * @param size The number of elements this dynamic array should hold. If this 
 * value is less than `DEFAULT_SIZE`, the returned dynamic array will be able 
 * to hold `DEFAULT_SIZE` items. If `size` is an odd number, it is incremented 
 * by 1 to make it an even number. This is done for ease of use.
 *
 * @return A dynamic array with the ability to store `size` elements initially.
 */
dynamic_array_t create_array(int size);

/**
 * Add `element` to `index` of `array`.
 *
 * @param array Dynamic array to add use.
 * @param index Where to put `element`.
 * @param element What to put into the array.
 */
void add(dynamic_array_t *array, int index, int element);

/**
 * Retrieves the element at the specified index.
 *
 * Since we have an array, we can do this in constant time, so O(1).
 *
 * @param array Dynamic array we want to use.
 * @param index The index whose element we want to retrieve.
 *
 * @return The element at the specified `index`.
 */
int get(dynamic_array_t array, int index);

/**
 * 
 */
int set(dynamic_array_t *array, int index, int number);

/**
 * 
 */
int remove_e(dynamic_array_t *array, int index);

/**
 * 
 */
void clear(dynamic_array_t *array);

/**
 * 
 */
bool contains(dynamic_array_t array, int number);

/**
 * 
 */
int index_of(dynamic_array_t array, int number);

/**
 * 
 */
int last_index_of(dynamic_array_t array, int number);

/**
 * 
 */
bool is_empty(dynamic_array_t array);

/**
 * 
 */
void print_array(dynamic_array_t array);