#include <stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

typedef struct array {
    int size;
    int* arr;
} Array;

void QuickSortIterative(Array A){
    Array stack[64];
    int top = -1;
    stack[++top] = A;
    while(top != -1){
        Array temp = stack[top--];
        if(temp.size > 1){
            int i = -1;
            for(int j = 0; j < temp.size; j++){
                if(temp.arr[j] <= temp.arr[temp.size - 1]){
                    i++;
                    swap(temp.arr + i, temp.arr + j);
                }
            }
            stack[++top] = (Array){i, temp.arr};
            stack[++top] = (Array){temp.size - i - 1, temp.arr + i + 1};
        }
    }
}

void PrintArray(Array A){
    for(int i = 0; i < A.size; i++){
        printf("%d ", A.arr[i]);
    }
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
    QuickSortIterative(A);
    printf("\nSorted Array : ");
    PrintArray(A);
}