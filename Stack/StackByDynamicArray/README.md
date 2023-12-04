# Stack Implementation in C

This C program provides a simple implementation of a stack using a dynamic array. The stack supports basic operations such as push, pop, peek, and provides functions to check if the stack is empty and to get its size and capacity.

## Overview

The project consists of one main structure:

- **Stack Structure:**
  - Represents the stack with a dynamic array, top index, current size, and capacity.

    ```c
    typedef struct {
        int *arr;
        int top;
        int size;
        int capacity;
    } Stack;
    ```

## Functions

- **`Initial(int cap)`:** Initializes and creates a stack with the given capacity.
- **`resize(Stack* stack)`:** Adjusts the capacity of the stack if needed.
- **`isEmpty(Stack* stack)`:** Checks if the stack is empty.
- **`push(Stack* stack, int elem)`:** Pushes an element onto the stack.
- **`pop(Stack* stack)`:** Pops an element from the stack.
- **`getPeak(Stack* stack)`:** Gets the top element without removing it.
- **`getSize(Stack* stack)`:** Gets the current size of the stack.
- **`getCapacity(Stack* stack)`:** Gets the current capacity of the stack.
- **`printStack(Stack* stack)`:** Prints the elements of the stack.

## Compilation and Usage

1. **Compilation:**
   - Compile the program using the following command:

    ```bash
    gcc -o stack stack.c
    ```

2. **Run the Program:**
   - Execute the compiled program:

    ```bash
    ./stack
    ```

## Example

```c
int main() {
    Stack *stack = Initial(5);
    printf("Size: %d\n", getSize(stack));
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    printStack(stack);
    printf("Stack size: %d\n", getSize(stack));
    printf("---------------------\n");
    printf("Peeked element: %d\n", getPeak(stack));
    free(stack);

    return 0;
}

Replace `your_program.c` with the name of your C source file.

To execute the compiled program:

```bash
./your_program

