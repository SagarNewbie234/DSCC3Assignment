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

void InsertionSort(int size, int* arr){
    printf("Sorting Process :\n\n");
    for(int i = 1; i < size; i++){
        int temp = arr[i], j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        printf("Pass %d : ", i);
        PrintArray(size, arr);
    }
}

void SelectionSort(int size, int* arr){
    printf("Sorting Process :\n\n");
    for(int i = 0; i < size - 1; i++){
        int minindex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        swap(arr + i, arr + minindex);
        printf("Pass %d : ", i + 1);
        PrintArray(size, arr);
    }
}

int main(){
    int size;
    printf("ARRAY SORT :\n\n");
    printf("Enter size : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter Array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array :");
    PrintArray(size, arr);

    int choice;
    do{
        printf("\nOPTIONS:\n1. Selection Sort\n2. Insertion Sort\n\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                SelectionSort(size, arr);
                printf("\nSorted Array : ");
                PrintArray(size, arr);
                break;
            case 2:
                InsertionSort(size, arr);
                printf("\nSorted Array : ");
                PrintArray(size, arr);
                break;
            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    }while(choice != 1 && choice != 2);
}