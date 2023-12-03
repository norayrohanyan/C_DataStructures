# Dynamic Array Library

## Structure of the Dynamic Array

The dynamic array is implemented using a structure named `DynamicArray`. It contains the following members:

- **`int *statArr`**: A pointer to the dynamically allocated array that stores the elements.
- **`int size`**: The current number of elements in the array.
- **`int capacity`**: The total capacity of the array.

## Integration Instructions

To integrate the dynamic array library into other projects, follow these steps:

1. Include the header file `dynamic_array.h` in your project.
2. Compile your project along with the source file `dynamic_array.c`.
3. Link the compiled object files.

Here is an example compilation command:

```bash
gcc your_project.c dynamic_array.c -o your_project

# Example Usage

```c
#include <stdio.h>
#include "dynamic_array.h"

int main() {
    // Initialize a dynamic array with an initial capacity of 5
    DynamicArray *arr = Initial(5);

    // Push elements into the array
    pushElement(arr, 20);
    pushElement(arr, 10);
    pushElement(arr, 30);

    // Insert elements at specific positions
    InsertElement(arr, 2, 15);
    InsertElement(arr, 0, 5);

    // Print the array
    printArray(arr);

    // Delete an element by index
    deleteByIndex(arr, 1);

    // Delete an element by value
    deleteByValue(arr, 30);

    // Print the array after deletion
    printArray(arr);

    // Get the size and capacity of the array
    printf("Size: %d\n", getSize(arr));
    printf("Capacity: %d\n", getCapacity(arr));

    // Sort the array
    sortArr(arr, 0, arr->size - 1);

    // Print the sorted array
    printArray(arr);

    // Free the memory allocated for the dynamic array
    free(arr->statArr);
    free(arr);

    return 0;
}
