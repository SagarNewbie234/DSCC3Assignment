#include <stdio.h>
#include <limits.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void PrintArray(int size, int* arr, const char* prompt){
    printf("%s", prompt);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int LinearSearch(int size, int* arr, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
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

    int search = LinearSearch(size, arr, key);
    if(search == INT_MIN){
        printf("RESULT : Key is not Found!\n");
    }else{
        printf("RESULT : %d is Found!\n", arr[search]);
    }
}