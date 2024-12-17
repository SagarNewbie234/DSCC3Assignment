#include <stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void PrintArray(int size, int* arr){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// MAX_HEAP

void UpHeapify(int size, int* arr){
    for(int j = size - 1; j > 0; j = (j - 1) / 2){
        if(arr[j] > arr[(j - 1) / 2]){
            swap(arr + j, arr + (j - 1) / 2);
        }
    }
}

void DownHeapify(int size, int* arr){
    int j = 0, maxindex;
    while(2*j + 1 < size){
        maxindex = 2*j + 1;
        if(2*j + 2 < size && arr[2*j + 1] < arr[2*j + 2]){
            maxindex = 2*j + 2;
        }
        if(arr[maxindex] <= arr[j]) break;
        swap(arr + maxindex, arr + j);
        j = maxindex;
    }
}

void CreateHeap(int size, int* arr){
    for(int i = 1; i < size; i++){
        UpHeapify(i + 1, arr);
    }
}

void HeapSort(int size, int* arr){
    CreateHeap(size, arr);
    for(int i = 0; i < size; i++){
        swap(arr, arr + size - 1 - i);
        DownHeapify(size - 1 - i, arr);
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

    printf("\nOriginal Array : ");
    PrintArray(size, arr);
    HeapSort(size, arr);
    printf("\nSorted Array : ");
    PrintArray(size, arr);
}