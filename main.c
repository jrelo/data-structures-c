#include <stdio.h>

#include "dynamic_array.h"
#include "singly_linked_list.h"

void test_dynamic_array();
void test_singly_linked_list();

int main(int argc, char **argv)
{
	test_singly_linked_list();
	
	return 0;
}

void test_singly_linked_list()
{
	singly_linked_list_t list = create_singly_linked_list();
	
	printf("value: %i\n", list.value);
	
	list.value = 1;
	
	printf("value: %i\n", list.value);
	
	singly_linked_list_t next = create_singly_linked_list();
	next.value = 2;
	
	list.next = &next;
	
	printf("contains: %i\n", contains_value(&list, 2));
}

void test_dynamic_array()
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
	
	printf("Index 2: %i\n", get(array, 2));
	printf("Index 3: %i\n", get(array, 3));
	printf("Index 7: %i\n\n", get(array, 7));
	
	delete(&array, 6);
	printf("Deleting index '6':\n");
	print_array(array);
	
	insert(&array, 5, 55);
	printf("Inserting '55' at index '5':\n");
	print_array(array);
	
	insert(&array, 10, 100);
	printf("Inserting '100' at index '10':\n");
	print_array(array);
	
	set(&array, 8, 45);
	printf("Setting index '8' to '45':\n");
	print_array(array);
	
	set(&array, 15, 32);
	printf("Setting index '15' to '32':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	delete(&array, 11);
	printf("Deleting index '11':\n");
	print_array(array);
	
	insert(&array, 8, 1);
	printf("Inserting '1' at index '8':\n");
	print_array(array);
}