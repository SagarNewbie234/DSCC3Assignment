#include <stdio.h>
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

Node* CreateHeader(){
    return CreateNode(INT_MAX);
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

void CreateLinkedList(Node* Header){
    FreeList(Header);
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
}

void Insert(Node* Header, int data){
    Node* newnode = CreateNode(data);
    Node* curr = Header;
    while(curr->next != NULL){
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
}

Node* SearchNode(Node* Header, int key){
    Node* ptr = Header->next;
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->next;
    }
    return ptr;
}

Node* Union(Node* Header1, Node* Header2){
    if(Header1->next == NULL || Header2->next == NULL){
        fprintf(stderr, "Cannot Find Union as One or Both of the lists are empty!\n");
        return NULL;
    }
    Node* UnionHeader = CreateHeader();
    Node* ptr = Header1->next;
    while(ptr != NULL){
        Node* Key = SearchNode(UnionHeader, ptr->data);
        if(Key == NULL){
            Insert(UnionHeader, ptr->data);
        }
        ptr = ptr->next;
    }
    ptr = Header2->next;
    while(ptr != NULL){
        Node* Key = SearchNode(UnionHeader, ptr->data);
        if(Key == NULL){
            Insert(UnionHeader, ptr->data);
        }
        ptr = ptr->next;
    }
    return UnionHeader;
}

Node* Intersection(Node* Header1, Node* Header2){
    if(Header1->next == NULL || Header2->next == NULL){
        fprintf(stderr, "Cannot Find Union as One or Both of the lists are empty!\n");
        return NULL;
    }
    Node* IntersectionHeader = CreateHeader();
    Node* ptr = Header1->next;
    while(ptr != NULL){
        Node* Key = SearchNode(Header2, ptr->data);
        if(Key != NULL){
            Insert(IntersectionHeader, ptr->data);
        }
        ptr = ptr->next;
    }
    
    return IntersectionHeader;
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
    Node* Header1 = CreateHeader();
    Node* Header2 = CreateHeader();
    
    CreateLinkedList(Header1);
    CreateLinkedList(Header2);
    Node* UnionH = Union(Header1, Header2);
    Node* IntersectionH = Intersection(Header1, Header2);

    printf("Linked List 1 : ");
    DisplayList(Header1);
    printf("Linked List 2 : ");
    DisplayList(Header2);
    printf("Union of List 1 and 2 : ");
    DisplayList(UnionH);
    printf("Intersection of List 1 and 2 : ");
    DisplayList(IntersectionH);
    printf("\n");

    FreeList(Header1);
    FreeList(Header2);
    FreeList(UnionH);
    FreeList(IntersectionH);

    free(Header1);
    free(Header2);
    free(UnionH);
    free(IntersectionH);
}