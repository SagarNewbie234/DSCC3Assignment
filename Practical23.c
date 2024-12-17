#include <stdio.h>

typedef struct array {
    int size;
    int* arr;
} Array;

void PrintArray(Array A){
    for(int i = 0; i < A.size; i++){
        printf("%d ", A.arr[i]);
    }
    printf("\n");
}

void merge(Array S, Array A, Array B){
    int i = 0, j = 0, k = 0;
    while(j < B.size && i < A.size){
        if(A.arr[i] < B.arr[j]) S.arr[k++] = B.arr[j++];
        else S.arr[k++] = A.arr[i++];
    }
    while(j < B.size) S.arr[k++] = B.arr[j++];
    while(i < A.size) S.arr[k++] = A.arr[i++];
}

void MergeSort(Array A){
    if(A.size <= 1) return;
    int mid = A.size / 2;
    int arrA[mid], arrB[A.size - mid];
    for(int i = 0; i < A.size; i++){
        if(i < mid) arrA[i] = A.arr[i];
        else arrB[i - mid] = A.arr[i];
    }
    MergeSort((Array){mid, arrA});
    MergeSort((Array){A.size - mid, arrB});
    merge(A, (Array){mid, arrA}, (Array){A.size - mid, arrB});
}

int main(){
    int size;
    printf("Enter size : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter Array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    Array A = {size, arr};

    printf("Original Array : ");
    PrintArray(A);
    MergeSort(A);
    printf("\nSorted Array : ");
    PrintArray(A);
}