#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct stack{
    Node* Top;
} Stack;

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

Stack CreateStack(){
    Stack s;
    s.Top = CreateNode(INT_MAX);
    return s;
}

void DeleteStack(Stack* s){
    Node* curr = s->Top->next;
    while(curr != NULL){
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    s->Top = NULL;
}

void Push(Stack* s, int data){
    Node* Header = s->Top;
    Node* newnode = CreateNode(data);
    newnode->next = Header->next;
    Header->next = newnode;
}

int Pop(Stack* s){
    Node* Header = s->Top;
    if(Header->next == NULL){
        printf("Stack UnderFlow!\n");
        return -1;
    }
    Node* ptr = Header->next;
    Header->next = ptr->next;
    int data = ptr->data;
    free(ptr);
    return data;
}

void Display(Stack* s){
    Node* Header = s->Top;
    Node* ptr = Header->next;
    if(ptr == NULL){
        printf("|Empty|\n\n");
    }else{
        printf("|%4d| <- TOP\n", ptr->data);
        ptr = ptr->next;
        while(ptr != NULL){
            printf("|%4d|\n", ptr->data);
            ptr = ptr->next;
        }
        printf("------\n\n");
    }
}

int main(){
    Stack s = CreateStack();
    int choice, value;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                Push(&s, value);
                break;
            case 2:
                value = Pop(&s);
                if(value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                Display(&s);
                break;
            case 4:
                DeleteStack(&s);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}