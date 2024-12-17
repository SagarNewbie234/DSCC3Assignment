#include <stdio.h>
#include <limits.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int Sorted(int size, int* arr){
    int flag = 1;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void QuickSort(int size, int* arr){
    if(size < 2) return;
    int pivotindex = size - 1;
    int i = -1;
    for(int j = 0; j < size; j++){
        if(arr[j] <= arr[pivotindex]){
            i++;
            swap(arr + i, arr + j);
        }
    }
    QuickSort(i, arr);
    QuickSort(size - i - 1, arr + i + 1);
}

void PrintArray(int size, int* arr, const char* prompt){
    printf("%s", prompt);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int BinarySearch(int size, int* arr, int key){
    if(!Sorted(size, arr)){
        QuickSort(size, arr);
    }
    int start = 0, end = size - 1, mid = (size - 1) / 2;
    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return INT_MIN;
}

int main(){
    int size, key;
    printf("Enter size : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter Array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    PrintArray(size, arr, "Array : ");
    
    printf("Enter Key to Search : ");
    scanf("%d", &key);

    int search = BinarySearch(size, arr, key);
    if(search == INT_MIN){
        printf("RESULT : Key is not Found!\n");
    }else{
        printf("RESULT : %d is Found!\n", arr[search]);
    }
}