#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* CreateNode(int data){
    Node* n = (Node*) calloc(1, sizeof(Node));
    if(n == NULL) perror("Node Not Created : ");
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Insert(Node** Root, int data){
    if(*Root == NULL){
        *Root = CreateNode(data);
        return;
    }
    if((*Root)->data > data){
        Insert(&(*Root)->left, data);
    }else{
        Insert(&(*Root)->right, data);
    }
}

void CreateTree(Node** Root){
    int size, data;
    printf("Enter No. of Nodes : ");
    scanf("%d", &size);
    printf("Enter Tree Nodes : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        Insert(Root, data);
    }
}

void PreorderTraverse(Node* Root){
    if(Root == NULL) return;
    printf("%d ", Root->data);
    PreorderTraverse(Root->left);
    PreorderTraverse(Root->right);
}

int CountNodes(Node* Root){
    if(Root == NULL) return 0;
    return CountNodes(Root->right) + CountNodes(Root->left) + 1;
}

void InorderTraverseIterative(Node* Root){
    int nodecount = CountNodes(Root);
    Node* stack[nodecount], *curr;
    int top = -1;
    curr = Root;
    while(1){
        if(curr != NULL){
            stack[++top] = curr;
            curr = curr->left;
        }else{
            if(top == -1) break;
            curr = stack[top--];
            printf("%d ", curr->data);
            curr = curr->right;
        }
        
    }
}

void DeleteTree(Node** Root){
    if(*Root == NULL) return;
    DeleteTree(&(*Root)->left);
    DeleteTree(&(*Root)->right);
    free(*Root);
    *Root = NULL;
}

int main(){
    Node* Root = NULL;
    CreateTree(&Root);
    printf("\nInorder Traversal : ");
    InorderTraverseIterative(Root);
    printf("\nPreorder Traversal : ");
    PreorderTraverse(Root);
    DeleteTree(&Root);
}