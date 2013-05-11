#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

dynamic_array_t create_array()
{
	return create_array_with_size(DEFAULT_SIZE);
}

dynamic_array_t create_array_with_size(int size)
{
	dynamic_array_t result;

	// If the size is less than the minimum, just use the minimum.
	if (size < DEFAULT_SIZE)
	{
		size = DEFAULT_SIZE;
	}
	
	// Also make sure the size, if specified, is an even number.
	if (size % 2 != 0)
	{
		size++;
	}
	
	// Assign the size and allocate enough memory for size.
	result.size = size;
	result.elements = calloc(result.size, sizeof(int));
	
	return result;
}

void insert(dynamic_array_t *array, int index, int number)
{
	// If the index doesn't make sense, don't do anything.
	if (index < 0)
	{
		return;
	}
	
	// Array's new size
	int new_size = array->size * 2;
	int *new_elements = calloc(new_size, sizeof(int));
	
	for (int i = 0, j = 0; i < array->size; i++, j++)
	{
		// This is the index we needed. Assign the value and move on to the 
		// next value.
		if (i == index)
		{
			new_elements[j] = number;
			j++;
			continue;
		}
		
		new_elements[j] = array->elements[i];
	}
	
	free(array->elements);
	
	array->elements = new_elements;
	array->size = new_size;	
}

int get(dynamic_array_t array, int index)
{
	// Make sure the index is valid. If not, return the error index.
	if (index >= array.size || index < 0)
	{
		return INVALID_INDEX;
	}
	
	// Grab the element at the specified index. O(1) FTW!.
	return array.elements[index];
}

void set(dynamic_array_t *array, int index, int number)
{
	if (index >= array->size || index < 0)
	{
		return;
	}
	
	array->elements[index] = number;
}

int delete(dynamic_array_t *array, int index)
{
	// Make sure the index is valid.
	if (index >= array->size || index < 0)
	{
		return INVALID_INDEX;
	}
	
	// Get the current value so we can return it.
	int result = get(*array, index);
	
	// Calculate the new potential size of the array
	int potential_new_size = array->size / 2;
	
	bool should_shrink = true;
	
	// Figure out if we can shrink the array
	for (int i = potential_new_size + 1; i < array->size; i++)
	{
		// We found a non-zero element. We can't shrink the array, so 
		// short-ciruit the loop.
		if (array->elements[i] > 0)
		{
			should_shrink = false;
			break;
		}
	}
	
	int *new_elements;
	
	if (should_shrink)
	{
		// Shrinking the array, so allocate a new memory location for the new 
		// smaller array.
		new_elements = calloc(potential_new_size, sizeof(int));
		
		// Now move all the existing values to the new memory location
		for (int i = 0; i < potential_new_size; i++)
		{
			new_elements[i] = array->elements[i];
		}
		
		// Set the array size.
		array->size = potential_new_size;
	}
	else
	{
		// We have to move every element up by one, so create a new memory 
		// location.
		new_elements = calloc(array->size, sizeof(int));
		
		// Now loop over the current memory location and move all the values to
		// a new lower index.
		for (int i = 0, j = 0; i < array->size - 1; i++, j++)
		{
			// This is the index we removed, so skip it.
			if (i == index)
			{
				j++;
			}
			
			new_elements[i] = array->elements[j];
		}
	}
	
	// Free the old memory location
	free(array->elements);
	
	// Assign the new memory location to the strcut
	array->elements = new_elements;
	
	// We're done. Return the value that was removed.
	return result;
}

void clear(dynamic_array_t *array)
{
	// Reset the size and free the memory location.
	array->size = 0;
	free(array->elements);
	
	// Reallocate a fresh new memory location for use.
	array->elements = calloc(DEFAULT_SIZE, sizeof(int));
}

bool contains(dynamic_array_t array, int number)
{
	bool result = false;
	
	for (int i = 0; i < array.size; i++)
	{
		if (get(array, i) == number)
		{
			result = true;
			
			break;
		}
	}
	
	return result;
}

int index_of(dynamic_array_t array, int number)
{
	int result = NOT_FOUND;
	
	for (int i = 0; i < array.size; i++)
	{
		if (get(array, i) == number)
		{
			result = i;
			
			break;
		}
	}
	
	return result;
}

int last_index_of(dynamic_array_t array, int number)
{
	int result = NOT_FOUND;
	
	for (int i = array.size - 1; i >= 0; i--)
	{
		if (get(array, i) == number)
		{
			result = i;
			
			break;
		}
	}
	
	return result;
}

bool is_empty(dynamic_array_t array)
{
	bool result = true;
	
	for (int i = 0; i < array.size; i++)
	{
		if (get(array, i) > 0)
		{
			result = false;
			
			break;
		}
	}
	
	return result;
}

void print_array(dynamic_array_t array)
{
	for (int i = 0; i < array.size; i++)
	{
		printf("%02i: %i\n", i, get(array, i));
	}
	
	printf("\n");
}
