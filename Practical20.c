#include <stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void BubbleSort(int size, int* arr){
    for(int i = size - 1; i > 0; i--){
        int swapped = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr+j, arr+j+1);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
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
    BubbleSort(size, arr);
    PrintArray(size, arr, "Sorted Array : ");
}