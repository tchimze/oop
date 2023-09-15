// Malloc and calloc are both functions in the C programming language that are used to dynamically allocate memory.
// Malloc: It allocates block of memory of a specified size and returns a pointer to the begining of the block. The memory allocated by malloc is not initialized.
// Calloc: It allocates block of memory of the specified size and initializes each byte in the block to zero.
// If successful malloc() returns a pointer to the allocated memory, else returns a null pointer.
// The memory must be freed because the when program exits the memory allocated by malloc and calloc is not automatically deallocated-which could lead to leaks, cause program to run out of memory, crash the program and other errors.


#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
	int *data;
	int size;
	int capacity;
} DynamicArray;

void init(DynamicArray *arr) {
	arr->data = malloc(INITIAL_CAPACITY * sizeof(int));
	arr->size = 0;
	arr->capacity = INITIAL_CAPACITY;
}

void append(DynamicArray *arr, int value) {
	if (arr->size == arr->capacity) {
		arr->capacity *=2;
		arr->data = realloc(arr->data, arr->capacity *sizeof(int));
	}
	arr->data[arr->size++] = value;
}

void free_array(DynamicArray *arr) {
	free(arr->data);
}

int main() {
	DynamicArray arr;
	init(&arr);

	for (int i = 0; i < 100; i++) {
		append(&arr, i);
	}

	for (int i =0; i < arr.size; i++) {
		printf("%d ", arr.data[i]);
	}
	printf("\n");

	free_array(&arr);

	return 0;
}
