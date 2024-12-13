#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

Node* CreateNode(int data){
    Node* newnode = (Node*) calloc(1, sizeof(Node));
    if(newnode == NULL){
        fprintf(stderr, "ERROR : Memory Allocation of Node Failed");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
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
        newnode->prev = curr;
        curr->next = newnode;
        curr = newnode;
    }
    return Header;
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

void DeleteAt(Node* Header, int pos){
    if(pos < 1){
        fprintf(stderr, "ERROR : Invalid Position Given for Delete Operation or List is Empty!\n");
    }else{
        Node* curr = Header;
        int i = 0;
        while(curr != NULL && i < pos){
            curr = curr->next;
            i++;
        }
        if(curr == NULL){
            fprintf(stderr, "ERROR : Given Position is Out of Index or List is Empty!\n");
        }else{
            Node* predecessor = curr->prev;
            Node* next = curr->next;
            predecessor->next = next;
            if(next != NULL) next->prev = predecessor;
            free(curr);
        }
    }
}

int main(){
    Node* Header = CreateLinkedList();

    printf("Linked List : ");
    DisplayList(Header);

    int k;
    printf("Enter Position you want to Delete at : ");
    scanf("%d", &k);

    DeleteAt(Header, k);

    printf("Linked List After Deletion : ");
    DisplayList(Header);

    FreeList(Header);
    free(Header);
}