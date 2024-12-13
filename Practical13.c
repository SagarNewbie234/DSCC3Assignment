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

Node* SearchPredecessor(Node* Header, int data){
    Node* ptr = Header;
    Node* ptr1 = Header->next;
    while(ptr1 != NULL && ptr1->data < data){
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    return ptr;
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
    Node* Header = CreateNode(INT_MAX);
    Node* newnode, *curr;
    int data, size;
    printf("Enter No. of Elements you want to Insert : ");
    scanf("%d", &size);
    printf("Enter List Elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        newnode = CreateNode(data);
        curr = SearchPredecessor(Header, data);
        newnode->next = curr->next;
        curr->next = newnode;
    }

    printf("Linked List : ");
    DisplayList(Header);
    FreeList(Header);
    free(Header);
}