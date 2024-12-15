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

Node* Search(Node* Root, int data){
    Node* Current = Root;
    while(Current != NULL){
        if(Current->data > data) Current = Current->left;
        else if(Current->data == data) return Current;
        else Current = Current->right;
    }
    return NULL;
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

void InorderTraverse(Node* Root){
    if(Root == NULL) return;
    InorderTraverse(Root->left);
    printf("%d ", Root->data);
    InorderTraverse(Root->right);
}

void PreorderTraverse(Node* Root){
    if(Root == NULL) return;
    printf("%d ", Root->data);
    PreorderTraverse(Root->left);
    PreorderTraverse(Root->right);
}

void PostorderTraverse(Node* Root){
    if(Root == NULL) return;
    PostorderTraverse(Root->left);
    PostorderTraverse(Root->right);
    printf("%d ", Root->data);
}

int CountLeaves(Node* Root){
    if(Root == NULL) return 0;
    if(Root->left == NULL && Root->right == NULL) return 1;
    return CountLeaves(Root->left) + CountLeaves(Root->right);
}

int CountInternalNodes(Node* Root){
    if(Root == NULL) return 0;
    if(Root->left == NULL && Root->right == NULL) return 0;
    return CountInternalNodes(Root->right) + CountInternalNodes(Root->left) + 1;
}

void SwapNodeData(Node** node1, Node** node2) {
    int temp = (*node1)->data;
    (*node1)->data = (*node2)->data;
    (*node2)->data = temp;
}

void DeleteNode(Node** Root, int data){
    if(*Root == NULL) return;
    if((*Root)->data > data){
        DeleteNode(&(*Root)->left, data);
    }else if((*Root)->data < data){
        DeleteNode(&(*Root)->right, data);
    }else{
        if((*Root)->left == NULL && (*Root)->right == NULL){
            free(*Root);
            *Root = NULL;
            return;
        }else{
            if((*Root)->right != NULL){
                Node** successor = &(*Root)->right;
                while((*successor)->left != NULL){
                    successor = &(*successor)->left;
                }
                SwapNodeData(Root, successor);
                DeleteNode(successor, data);
            }else if((*Root)->left != NULL){
                Node** predecessor = &(*Root)->left;
                while((*predecessor)->right != NULL){
                    predecessor = &(*predecessor)->right;
                }
                SwapNodeData(Root, predecessor);
                DeleteNode(predecessor, data);
            }
        }
    }
}

void DisplayLevelWise(Node* Root){
    int nodecount = CountInternalNodes(Root) + CountLeaves(Root);
    Node* queue[nodecount];
    int front = 0, rear = 0;
    queue[0] = Root;
    Node* Curr;
    while(front != nodecount){
        Curr = queue[front++];
        if(Curr->left != NULL){
            queue[++rear] = Curr->left;
        }
        if(Curr->right != NULL){
            queue[++rear] = Curr->right;
        }
        printf("%d ", Curr->data);
    }
}

void DisplayIndented(Node* Root, int space){
    if(Root == NULL) return;
    space += 5;
    DisplayIndented(Root->right, space);
    for(int i = 5; i < space; i++) printf(" ");
    printf("%d\n", Root->data);
    DisplayIndented(Root->left, space);
}

void DeleteTree(Node** Root){
    if(*Root == NULL) return;
    DeleteTree(&(*Root)->left);
    DeleteTree(&(*Root)->right);
    free(*Root);
    *Root = NULL;
}

int main() {
    Node* Root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Create Tree\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search for an Element\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Count All Nodes\n");
        printf("8. Delete a Node\n");
        printf("9. Display Level-wise\n");
        printf("10. Display Tree Indented\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                DeleteTree(&Root);
                CreateTree(&Root);
                break;

            case 2:
                if (Root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order Traversal: ");
                    InorderTraverse(Root);
                    printf("\n");
                }
                break;

            case 3:
                if (Root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Pre-order Traversal: ");
                    PreorderTraverse(Root);
                    printf("\n");
                }
                break;

            case 4:
                if (Root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Post-order Traversal: ");
                    PostorderTraverse(Root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (Search(Root, value)) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;

            case 6:
                printf("Number of leaf nodes: %d\n", CountLeaves(Root));
                break;

            case 7:
                printf("Leaf Nodes : %d\n", CountLeaves(Root));
                printf("Non-leaf Nodes : %d\n", CountInternalNodes(Root));
                break;

            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                DeleteNode(&Root, value);
                printf("Node with value %d deleted (if it existed).\n", value);
                break;

            case 9:
                if (Root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Level-wise Traversal: ");
                    DisplayLevelWise(Root);
                    printf("\n");
                }
                break;

            case 10:
                if (Root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Indented Display:\n");
                    DisplayIndented(Root, 0);
                }
                break;

            case 11:
                printf("Exiting...\n");
                DeleteTree(&Root);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}
