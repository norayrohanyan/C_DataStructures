# Stack Implementation

## Overview

This project implements a basic stack data structure in C. The stack is designed using a linked list, and the program provides functions for initializing a stack, pushing elements onto it, popping elements off it, checking if it's empty, retrieving its peak element, and getting its size.

## Compilation and Execution

To compile the program, follow these steps:

```bash
gcc your_program.c -o your_program

Replace `your_program.c` with the name of your C source file.

To execute the compiled program:

```bash
./your_program

# Stack Library Example

## Usage Example

```c
#include <stdio.h>
#include "stack.h"

# Stack Library Example

## Usage Example

```c
#include <stdio.h>
#include "stack.h"

int main() {
    // Initialize a stack
    Stack *stack = Initial();

    // Push elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Pop elements from the stack
    int poppedValue = pop(stack);

    // Check if the stack is empty
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    // Print the current elements in the stack
    printStack(stack);

    // Get the size of the stack
    printf("Size of the stack: %d\n", getSize(stack));

    // Get the peak element of the stack
    printf("Peak element: %d\n", getPeak(stack));

    // Free the memory allocated for the stack
    free(stack);

    return 0;
}
