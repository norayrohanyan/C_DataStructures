#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *statArr;
    int size;
    int capacity;
} DynamicArray;

// Function declarations
DynamicArray* Initial(int initialCapacity);
void pushElement(DynamicArray *arr, int element);
void deleteByIndex(DynamicArray *arr, int index);
void deleteByValue(DynamicArray *arr, int val);
int getElement(DynamicArray *arr, int index);
int getSize(DynamicArray *arr);
int getCapacity(DynamicArray *arr);
void InsertElement(DynamicArray *arr, int index, int elem);
void printArray(DynamicArray *arr);
void sortArr(DynamicArray *arr, int start, int end);
int partition(DynamicArray *arr, int start, int end);

int main() {

    DynamicArray *arr = Initial(5);

    // Insert values into the array
    pushElement(arr, 10);
    pushElement(arr, 5);
    pushElement(arr, 8);
    pushElement(arr, 2);
    pushElement(arr, 15);

    // Print the initial array
    printArray(arr);
    printf("Current size %d\n", getSize(arr));
    printf("Current capacity %d\n", getCapacity(arr));

    // Insert an element
    InsertElement(arr, 2, 12);
    printArray(arr);
    printf("Current size: %d\n", getSize(arr));
    printf("Current capacity: %d\n", getCapacity(arr));

    // Delete elements
    deleteByIndex(arr, 3);
    deleteByIndex(arr, 2);
    deleteByIndex(arr, 1);

    printArray(arr);
    printf("Current size: %d\n", getSize(arr));
    printf("Current capacity: %d\n", getCapacity(arr));

    // Delete element with value
    deleteByValue(arr, 2);
    printArray(arr);
    printf("Current size: %d\n", getSize(arr));
    printf("Current capacity: %d\n", getCapacity(arr));

    int elementAtIndex1 = getElement(arr, 1);
    printf("Element at index 1: %d\n", elementAtIndex1);

    pushElement(arr, 7);
    pushElement(arr, 20);
    pushElement(arr, 3);

    // Sort the array
    sortArr(arr, 0, getSize(arr) - 1);
    printf("Array after sorting:\n");
    printArray(arr);

    // free memory
    free(arr->statArr);
    free(arr);

    return 0;
}

DynamicArray* Initial(int cap) {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));

    arr->statArr = (int*)malloc(cap * sizeof(int));

    if (arr->statArr == NULL) {
        // Handle memory allocation failure
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->size = 0;
    arr->capacity = cap;

    return arr;
}

void resizeDynamicArray(DynamicArray *arr) {
    if (arr->capacity / 4 >= arr->size) {
        arr->capacity = arr->size + 1;
        arr->statArr = (int*)realloc(arr->statArr, arr->capacity * sizeof(int));
    }
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->statArr = (int*)realloc(arr->statArr, arr->capacity * sizeof(int));
    }

    if (arr->statArr == NULL) {
        // Handle memory reallocation failure
        exit(EXIT_FAILURE);
    }
}

void pushElement(DynamicArray *arr, int elem) {

    resizeDynamicArray(arr);    // if the array is full, resize it
    arr->statArr[arr->size++] = elem;   // increment the last index and assign the element
}

void InsertElement(DynamicArray *arr, int index, int elem) {
    if (arr->size == arr->capacity) {   // if the array is full, resize it
        resizeDynamicArray(arr);
    }
    if ((index > arr->size) || (index < 0)) {    // checking for valid index
        printf("Invalid index \n");
        return;
    }

    for (int i = arr->size - 1; i >= index; --i) {
        arr->statArr[i + 1] = arr->statArr[i];      // shifting elements to the right to make space for the new element
    }
    arr->statArr[index] = elem;
    arr->size++;
}

void deleteByIndex(DynamicArray *arr, int index) {
    if ((index > arr->size) || (index < 0)) {
        printf("Invalid index \n");
        return;
    }

    if (arr->size == 0) {
        return;
    }

    for (int i = index; i < arr->size - 1; ++i) {
        arr->statArr[i] = arr->statArr[i + 1];    // shifting elements to the left to fill the gap created by the deleted element
    }
    arr->size--;    // decrement size
    resizeDynamicArray(arr);    // resize array
}

void deleteByValue(DynamicArray *arr, int val) {    
    for (int i = 0; i < arr->size; ++i) {
        if (arr->statArr[i] == val) {
            deleteByIndex(arr, i);
            break;
        }
    }
}

int getElement(DynamicArray *arr, int index) {
    if (index > arr->size) {
        printf("Invalid index \n");
        return -1;
    }

    return arr->statArr[index];
}

int getSize(DynamicArray *arr) {    // return size
    return arr->size;
}

int getCapacity(DynamicArray *arr) {    // return capacity
    return arr->capacity;
}

void printArray(DynamicArray *arr) {    // print array
    printf("Elements in the array: ");
    for (int i = 0; i < arr->size; ++i) {
        printf("%d ", arr->statArr[i]);
    }
    printf("\n");
}

// sorting array by quick sort
void sortArr(DynamicArray *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = partition(arr, start, end);
    sortArr(arr, start, pivot - 1);
    sortArr(arr, pivot + 1, end);
}

int partition(DynamicArray *arr, int start, int end) {
    int pivot = arr->statArr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr->statArr[j] < pivot) {
            ++i;
            int tmp = arr->statArr[i];
            arr->statArr[i] = arr->statArr[j];
            arr->statArr[j] = tmp;
        }
    }
    ++i;
    int tmp = arr->statArr[i];
    arr->statArr[i] = arr->statArr[end];
    arr->statArr[end] = tmp;
    return i;
}