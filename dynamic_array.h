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
 * Allocates and prepares a dynamic array type a capacity to hold `DEFAULT_SIZE`
 * items.
 *
 * @return A dynamic array with the allocated space to hold `DEFAULT_SIZE` 
 * items.
 *
 * @see create_array_with_size(int)
 */
dynamic_array_t create_array();

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
 *
 * @see create_array()
 */
dynamic_array_t create_array_with_size(int size);

/**
 * Inserts `element` at `index` of `array`.
 *
 * The size of the underlaying array is doubled every time a value is inserted 
 * at a particular index. Therefore, this is an O(n) operation.
 *
 * @param array Dynamic array to use.
 * @param index Where to put `element`.
 * @param number What to put into the array.
 *
 * @see delete(dynamic_array_t *, int)
 */
void insert(dynamic_array_t *array, int index, int number);

/**
 * Retrieves the element at the specified index.
 *
 * Since we have an array, we can do this in constant time, so O(1).
 *
 * @param array Dynamic array we want to use.
 * @param index The index whose element we want to retrieve.
 *
 * @return The element at the specified `index`. If `index` is outside of the 
 * bounds of `array`'s size, `INVALID_INDEX` is returned.
 *
 * @see set(dynamic_array_t *, int, int);
 */
int get(dynamic_array_t array, int index);

/**
 * Sets the value of `index` to `number`. `index` must be within the bounds of 
 * array's size. If `index` is less or greater than array's size, 
 * `INVALID_INDEX` is returned.
 *
 * @param array The array to use.
 * @param index The index at which `number` should be set.
 * @param number The value to set.
 *
 * @see get(dynamic_array_t, int);
 */
void set(dynamic_array_t *array, int index, int number);

/**
 * Deletes the value at `index` and shrinks the size of the underlaying array 
 * if necessary.
 *
 * Since the underlaying data structure is modified, this function is O(n) in 
 * the worst case.
 *
 * @param array The dynamic array to use.
 * @param index The index whose value is to be removed.
 *
 * @return Returns the deleted value. If `index` is outside of the bounds of 
 * `array`'s size, `INVALID_INDEX` is returned.
 * 
 * @see insert(dynamic_array_t *, int, int);
 */
int delete(dynamic_array_t *array, int index);

/**
 * Clears out the array by freeing the existing memory location and allocating 
 * a new one. All values will be discarded.
 *
 * @param array The array to clear.
 *
 * @see is_empty(dynamic_array_t *)
 */
void clear(dynamic_array_t *array);

/**
 * Determines whether `array` contains `number`.
 *
 * The worst case complexity for this function is O(n)
 *
 * @param array The array to search.
 * @param number The value to look for.
 *
 * @return If `array` contains `number`, `true`. Otherwise, `false`.
 *
 * @see index_of(dynamic_array_t, int)
 */
bool contains(dynamic_array_t array, int number);

/**
 * Traverses `array` to find `number` and then returns the index within `array`
 * for `number`.
 *
 * @param array The array to search.
 * @param number The value whose index we need.
 *
 * @return Traverses `array` to find `number`. If `number` is found, its index 
 * is returned. If `number` isn't found, `INVALID_INDEX` is returned.
 *
 * @see last_index_of(dynamic_array_t, int)
 */
int index_of(dynamic_array_t array, int number);

/**
 * Traverses `array` in reverse order to find `number` and then returns the 
 * first index from the end within `array` for `number`.
 *
 * @param array The array to search.
 * @param number The value whose index we need.
 *
 * @return Traverses `array` in reverse order to find `number`. If `number` is 
 * found, its index is returned. If `number` isn't found, `INVALID_INDEX` is 
 * returned.
 *
 * @see last_index_of(dynamic_array_t, int)
 */
int last_index_of(dynamic_array_t array, int number);

/**
 * Determines whether `array` is empty.
 *
 * @param array The array to use.
 *
 * @return If `array` doesn't have any elements in it, `true`. Otherwise, 
 * `false`.
 *
 * @see clear(dynamic_array_t *)
 */
bool is_empty(dynamic_array_t array);

/**
 * Prints the contents of `array` with an extra new line (`\n`) character for 
 * better visual seperation.
 *
 * @param array The array whose contents should be printed.
 */
void print_array(dynamic_array_t array);
