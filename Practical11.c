#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* CreateNode(int data){
    Node* newnode = (Node*) calloc(1, sizeof(Node));
    if(newnode == NULL){
        fprintf(stderr, "ERROR : Memory Allocation of Node Failed");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void FreeList(Node* Header){
    Node* curr = Header->next;
    while(curr != NULL){
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    Header->next = NULL;
}

Node* CreateLinkedList(){
    Node* Header = CreateNode(INT_MAX);
    Node* curr = Header, *newnode;
    int data, size;
    printf("Enter No. of Elements you want to Insert : ");
    scanf("%d", &size);
    if(size % 2 == 1){
        fprintf(stderr, "ERROR : Size of Linked List is Odd. Please enter an even size\n");
        free(Header);
        exit(1);
    }
    printf("Enter List Elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        newnode = CreateNode(data);
        curr->next = newnode;
        curr = newnode;
    }
    return Header;
}

void InterchangeOddAndEven(Node* Header){
    Node* ptr = Header;
    while(ptr->next != NULL){
        Node* ptr1 = ptr->next;
        Node* ptr2 = ptr1->next;
        Node* ptr3 = ptr2->next;

        ptr->next = ptr2;
        ptr2->next = ptr1;
        ptr1->next = ptr3;

        ptr = ptr1;
    }
}

void DisplayList(Node* Header){
    Node* curr = Header->next;
    if(curr == NULL){
        printf("NULL\n");
    }else{
        while(curr != NULL){
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main(){
    Node* Header = CreateLinkedList();

    printf("Original Linked List : ");
    DisplayList(Header);

    InterchangeOddAndEven(Header);

    printf("Linked List after interchanging odd and even positioned elements : ");
    DisplayList(Header);

    FreeList(Header);
    free(Header);
}