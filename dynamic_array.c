#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

dynamic_array_t create_array(int size)
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

void add(dynamic_array_t *array, int index, int element)
{
	// If the index doesn't make sense, don't do anything.
	if (index < 0)
	{
		return;
	}
	
	// If we have enough space, just put the value in the requested location.
	if (index < array->size)
	{
		array->elements[index] = element;
	}
	else
	{
		// Our underlaying array is too small. Expand it.
		
		// Get the current size.
		int new_size = array->size;
		
		// Double the size until we can address the requested index.
		while (new_size <= index)
		{
			new_size *= 2;
		}
		
		// Allocate and zero out a new memory location with enough space for 
		// the requested index.
		int *new_elements = calloc(new_size, sizeof(int));
		
		// Get all the values from the old location to the new one.
		for (int i = 0; i < array->size; i++)
		{
			new_elements[i] = array->elements[i];
		}
		
		// Free the old structure.
		free(array->elements);
		
		// Assign the new data structure and set the size
		array->elements = new_elements;
		array->size = new_size;
		
		// Finally, assign the value to the requsted index.
		array->elements[index] = element;
	}
}

int get(dynamic_array_t array, int index)
{
	// Make sure the index is valid. If not, return the error index.
	if (index >= array.size)
	{
		return INVALID_INDEX;
	}
	
	// Grab the element at the specified index. O(1) FTW!.
	return array.elements[index];
}

int set(dynamic_array_t *array, int index, int number)
{
	if (index >= array->size || index < 0)
	{
		return INVALID_INDEX;
	}
	
	array->elements[index] = number;
	
	return get(*array, index);
}

int remove_e(dynamic_array_t *array, int index)
{
	if (index >= array->size || index < 0)
	{
		return INVALID_INDEX;
	}
	
	int result = array->elements[index];
	
	array->elements[index] = 0;
	
	return result;
}

void clear(dynamic_array_t *array)
{
	array->size = 0;
	free(array->elements);
	
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
		if (get(array, i) != 0)
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