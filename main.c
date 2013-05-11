#include <stdio.h>

#include "dynamic_array.h"

int main(int argc, char **argv)
{
	dynamic_array_t array = create_array();
	
	printf("Creating brand new array:\n");
	print_array(array);
	
	set(&array, 2, 58);
	set(&array, 6, 43);
	
	printf("Setting a couple of values:\n");
	print_array(array);
	
	set(&array, 10, 200);
	
	printf("Setting index '10' to '200':\n");
	print_array(array);
	
	insert(&array, 3, 69);
	
	printf("Inserting '69' at index '3':\n");
	print_array(array);
	
	set(&array, 8, 100);

	printf("Setting index '8' to '100':\n");
	print_array(array);
	
	printf("Index 2: %i\n", get(array, 2));
	printf("Index 3: %i\n", get(array, 3));
	printf("Index 8: %i\n\n", get(array, 8));
	
	delete(&array, 6);
	
	printf("Deleting index '6':\n");
	print_array(array);
	
	return 0;
}
