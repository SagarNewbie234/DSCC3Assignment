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
    printf("Enter List Elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        newnode = CreateNode(data);
        curr->next = newnode;
        curr = newnode;
    }
    return Header;
}

void SwapKthNode(Node* Header, int k){
    if(k < 1){
        fprintf(stderr, "ERROR : Invalid Value of K\n");
        exit(1);
    }
    Node* ptr1 = Header;
    Node* ptr = Header->next;
    int i = 1;
    while(ptr != NULL && i < k){
        ptr1 = ptr1->next;
        ptr = ptr->next;
        i++;
    }
    Node* ptr2 = ptr->next;

    if(ptr2 == NULL){
        fprintf(stderr, "ERROR : No Node at K+1 th Position, Swap Terminated\n");
        exit(1);
    }

    Node* ptr3 = ptr2->next;
    ptr1->next = ptr2;
    ptr2->next = ptr;
    ptr->next = ptr3;
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

    printf("Linked List : ");
    DisplayList(Header);

    int k;
    printf("Enter Value of K : ");
    scanf("%d", &k);
    SwapKthNode(Header, k);

    printf("Linked List after swapping %d th and %d th Element : ", k, k+1);
    DisplayList(Header);

    FreeList(Header);
    free(Header);
}