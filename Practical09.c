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

void InsertFront(Node* Header, int data){
    Node* newnode = CreateNode(data);
    newnode->next = Header->next;
    Header->next = newnode;
}

Node* CreateLinkedList(){
    Node* Header = CreateNode(INT_MAX);
    Node* curr = Header, *newnode;
    int data, size;
    printf("Enter No. of Elements you want to Insert : ");
    scanf("%d", &size);
    printf("Enter List Elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        newnode = CreateNode(data);
        curr->next = newnode;
        curr = newnode;
    }
    return Header;
}

Node* ReverseList(Node* Header){
    Node* ptr = Header->next;
    Node* ReversedHeader = CreateHeader();
    while(ptr != NULL){
        InsertFront(ReversedHeader, ptr->data);
        ptr = ptr->next;
    }
    return ReversedHeader;
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
    Node* Reversed = ReverseList(Header);

    printf("Linked List : ");
    DisplayList(Header);
    printf("Reversed Linked List : ");
    DisplayList(Reversed);

    FreeList(Header);
    FreeList(Reversed);
    free(Header);
    free(Reversed);
}