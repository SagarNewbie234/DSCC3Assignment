#include <stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void SelectionSort(int size, int* arr){
    for(int i = 0; i < size; i++){
        int minindex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        swap(arr + i, arr + minindex);
    }
}

void PrintArray(int size, int* arr, const char* prompt){
    printf("%s", prompt);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    PrintArray(size, arr, "Original Array : ");
    SelectionSort(size, arr);
    PrintArray(size, arr, "Sorted Array : ");
}