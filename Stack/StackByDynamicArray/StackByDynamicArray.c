#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 4

//defining type for Stack structure 
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;


// functions prototypes
Stack* Initial(int cap);
void resize(Stack* stack);
void push(Stack* stack, int elem);
void printStack(Stack *arr);
int pop(Stack* stack);
int getPeak(Stack* stack);
int getSize(Stack* stack);
int getCapacity(Stack* stack);
int isEmpty(Stack* stack);


int main() {
    Stack *arr = Initial(INIT_CAPACITY);    // initialize a stack

    // pushing elements in the stack
    push(arr, 10);
    push(arr, 20);
    push(arr, 30);

    printStack(arr);

    int poppedElement = pop(arr);
    printf("Popped element %d\n", poppedElement);

    int topElement = getPeak(arr);
    printf("Top element %d\n", topElement);

    printStack(arr);

    printf("Is the stack empty? %s\n", isEmpty(arr) ? "Yes" : "No");

    printf("size %d\n", getSize(arr));
    printf("capacity %d\n", getCapacity(arr));

    push(arr, 40);
    push(arr, 50);

    printStack(arr);

    free(arr->arr);
    free(arr);
    arr = NULL;

    return 0;
}


Stack* Initial(int cap) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));    // take memory for the stack structure
    stack->arr = (int *)malloc(cap * sizeof(int));    // take memory for the stack's array (elements)
    stack->capacity = cap;  // initialize the stacks properties and return the stack
    stack->top = -1;
    return stack;
}

void resize(Stack* stack) {
    if (stack->capacity / 4 >= getSize(stack)) {    // if space is less than a quarter of the array is used, shrink array
        stack->capacity = getSize(stack) + 1;
        stack->arr = realloc(stack->arr, stack->capacity * sizeof(int));
    }
    if (getSize(stack) == stack->capacity) {    // resize array when size reaches capacity
        stack->capacity *= 2;
        stack->arr = realloc(stack->arr, stack->capacity * sizeof(int));
    }
}

void push(Stack* stack, int elem) {
    resize(stack);  // resizing array
    stack->arr[++stack->top] = elem;    // increment the last index and assign the element
}

int pop(Stack* stack) {
    if (stack->top == -1) {    // checking for stack underflow, if stack is empty    
        printf("Stack is empty");
        exit(EXIT_FAILURE);
    }
    int res = stack->arr[stack->top--]; // decrement the last index and resize array
    resize(stack);
    return res;
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) { // checking if stack is empty
        return 1;
    }
    return 0;
}

int getPeak(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty \n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];  // return the top element of the stack
}

int getSize(Stack* stack) {
    return stack->top + 1;  // return size
}

int getCapacity(Stack* stack) {
    return stack->capacity;  // return capacity
}

void printStack(Stack *arr) {   //print stack
    printf("Elements in the Stack: ");
    for (int i = 0; i < getSize(arr); ++i) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}