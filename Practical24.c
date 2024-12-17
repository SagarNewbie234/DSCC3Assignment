#include <stdio.h>
#include <math.h>

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

void MergeSortIterative(Array A) {
    int passes = (int)ceil(log2(A.size));
    int space[passes + 1][A.size];
    for (int i = 0; i < A.size; i++) space[0][i] = A.arr[i];
    
    int pass = 0;
    while (pass < passes) {
        int blockSize = (int)pow(2, pass);
        int mergeSize = blockSize * 2;
        
        for (int start = 0; start < A.size; start += mergeSize) {
            int* arrA = space[pass] + start;
            int* arrB = arrA + blockSize;
            
            int sizeA = blockSize;
            int sizeB = blockSize;
            
            if (start + blockSize > A.size) sizeA = A.size - start;
            if (start + mergeSize > A.size) sizeB = A.size - (start + blockSize);
            
            int* arrS = space[pass + 1] + start;
            
            int i = 0, j = 0, k = 0;
            
            while (i < sizeA && j < sizeB) {
                if (arrA[i] <= arrB[j]) arrS[k++] = arrA[i++];
                else arrS[k++] = arrB[j++];
            }
            while (i < sizeA) arrS[k++] = arrA[i++];
            while (j < sizeB) arrS[k++] = arrB[j++];
        }
        pass++;
    }
    
    for (int i = 0; i < A.size; i++) A.arr[i] = space[passes][i];
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
    MergeSortIterative(A);
    printf("\nSorted Array : ");
    PrintArray(A);
}