#include <stdio.h>
#include <stdlib.h>

//defining type for Node structure 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//defining type for Stack structure 
typedef struct {
    Node* head;
} Stack;


// functions prototypes
Stack* Initial();
void push(Stack* stack, int elem);
int pop(Stack* stack);
void printStack(Stack *arr);
int getPeak(Stack* stack);
int getSize(Stack* stack);
int isEmpty(Stack* stack); 

int main() {
    Stack *stack = Initial();

    push(stack, 1);
    push(stack, 2);    
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);

    int c = pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    // pop(stack);
    // pop(stack);
    // pop(stack);

    printf("Is Empty? ");
    if (isEmpty(stack)) {
        printf("yes");
    }
    else {
        printf("no");
    }
    printf("\n");
   
    printStack(stack);
    printf("size %d", getSize(stack));
    printf("\n");
    printf("peak %d", getPeak(stack));
    printf("\n");


    
    free(stack); 
    stack = NULL;
    return 0;
}

Stack* Initial() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // take space from dynamic memory for stack struct
    stack->head = NULL; // initialize head by null
    return stack;
}

void push(Stack* stack, int elem) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // take space from dynamic memory for node struct
    newNode->data = elem;   // initialize node properties
    newNode->next = NULL;
    if (!stack->head) { // checking if head is null
        stack->head = newNode;
    }
    else {
        Node* curr = stack->head;   // keeping the head reference in curr for not loosing original head
        while(curr->next) { 
            curr = curr->next;  // go forward while reaching the last node
        }
        curr->next = newNode;
    }
}

int pop(Stack* stack) {
     if (!stack->head) {  // checking if stack is empty, printing error and exit
        printf("Stack is empty");
        exit(EXIT_FAILURE);
    }
    if (!stack->head->next) {  // cheching for only one element, remove it and return its data
        Node* tmp = stack->head;  // keep the current head in a tmp pointer, for not loosing original head
        int data = tmp->data;   // keep the value of tmp in data
        stack->head = NULL;
        free(tmp);  // free the memory for deleted node
        return data;
    }

    Node* curr = stack->head;
    while(curr->next && curr->next->next) {  // go to the penultimate node, remove the last node
        curr = curr->next;
    }
    Node* tmp = curr->next;
    int data = tmp->data;
    curr->next = NULL;
    free(tmp);
    return data;   
}

int isEmpty(Stack* stack) {
    if (stack->head == NULL) {  // checking if stack is empty
        return 1;
    }
    return 0;
}

int getPeak(Stack* stack) {
    if (isEmpty(stack)) {   // checking if stack is empty, print error and return
        printf("Stack is empty \n");
        exit(EXIT_FAILURE);
    }
    else {
        Node* curr = stack->head;   // go forward until last element
        while(curr->next) {     
            curr = curr->next;
        }
        return curr->data;
    }
}

int getSize(Stack* stack) {  // checking if stack is empty, return 0
    if (isEmpty(stack)) {
        return 0;
    }
    int size = 1;   // counting number of nides
    Node* curr = stack->head;
    while(curr->next) {
        size++;
        curr = curr->next;
    }
    return size;
    
}

void printStack(Stack *arr) {
    printf("Elements in the Stack: ");
    Node* curr = arr->head;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    
    printf("\n");
}