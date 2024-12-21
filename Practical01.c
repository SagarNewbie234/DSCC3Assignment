#include <stdio.h>
#include <assert.h>
#define MAX 10

int inputArray(int* arr, const char* prompt){
    int size = 0;
    printf("%s\n", prompt);
    printf("Enter Size : ");
    scanf("%d", &size);
    assert(size <= MAX);
    printf("Enter Array : ");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("\n");
    return size;
}

int mergeArray(int size1, int* arr1, int size2, int* arr2){
    assert(size1 + size2 <= MAX);
    for(int i = size1; i < size1 + size2; i++) arr1[i] = arr2[i - size1];
    return size1 + size2;
}

void printArray(int size, int* arr, const char* prompt){
    printf("%s", prompt);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr1[MAX], arr2[MAX];
    int size1 = inputArray(arr1, "Array 1:");
    int size2 = inputArray(arr2, "Array 2:");
    printArray(size1, arr1, "Array 1 before Merging : ");
    printArray(size2, arr2, "Array 2 before Merging : ");
    size1 = mergeArray(size1, arr1, size2, arr2);
    printArray(size1, arr1, "Array 1 after Merging : ");
    printArray(size2, arr2, "Array 2 after Merging : ");
}