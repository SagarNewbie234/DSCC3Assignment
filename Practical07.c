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

Node* CreateHeader(){
    return CreateNode(INT_MAX);
}

void InsertAfter(Node* Header, int data, int pos){
    if(pos < 0){
        fprintf(stderr, "ERROR : Invalid Position Given for Insert Operation!\n");
    }else{
        Node* newnode = CreateNode(data);
        Node* curr = Header;
        int i = 0;
        while(curr != NULL && i < pos){
            curr = curr->next;
            i++;
        }
        if(curr == NULL){
            fprintf(stderr, "ERROR : Given Position is Out of Index!\n");
            free(newnode);
        }else{
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }
}

void DeleteAt(Node* Header, int pos){
    if(pos < 1){
        fprintf(stderr, "ERROR : Invalid Position Given for Delete Operation or List is Empty!\n");
    }else{
        Node* curr = Header;
        int i = 1;
        while(curr->next != NULL && i < pos){
            curr = curr->next;
            i++;
        }
        if(curr->next == NULL){
            fprintf(stderr, "ERROR : Given Position is Out of Index or List is Empty!\n");
        }else{
            Node* deleted = curr->next;
            Node* next = deleted->next;
            curr->next = next;
            free(deleted);
        }
    }
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

int CountListNodes(Node* Header){
    int i = 0;
    Node* curr = Header->next;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    return i;
}


void SeperateIntoOddEven(Node* Main, Node* Even, Node* Odd){
    FreeList(Even);
    FreeList(Odd);
    Node* curr = Main->next;
    while(curr != NULL){
        if(curr->data % 2 == 0){
            InsertAfter(Even, curr->data, CountListNodes(Even));
        }else{
            InsertAfter(Odd, curr->data, CountListNodes(Odd));
        }
        curr = curr->next;
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

void DeleteEnd(Node* Header){
    DeleteAt(Header, CountListNodes(Header));
}

int main() {
    Node* Header = CreateHeader();
    Node* Even = CreateHeader();
    Node* Odd = CreateHeader();

    int choice, data, pos;
    printf("**** Linked List Operations ****\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Separate into Odd and Even Lists\n");
        printf("5. Display Odd List\n");
        printf("6. Display Even List\n");
        printf("7. Delete Last Element\n");
        printf("8. Count Elements\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position after which to insert: ");
                scanf("%d", &pos);
                InsertAfter(Header, data, pos);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                DeleteAt(Header, pos);
                break;

            case 3:
                printf("Current List: ");
                DisplayList(Header);
                break;

            case 4:
                SeperateIntoOddEven(Header, Even, Odd);
                printf("Odd and Even lists separated.\n");
                break;

            case 5:
                printf("Odd List: ");
                DisplayList(Odd);
                break;

            case 6:
                printf("Even List: ");
                DisplayList(Even);
                break;

            case 7:
                DeleteEnd(Header);
                printf("Last element deleted.\n");
                break;

            case 8:
                printf("Number of elements in the list: %d\n", CountListNodes(Header));
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    FreeList(Header);
    FreeList(Even);
    FreeList(Odd);

    free(Header);
    free(Even);
    free(Odd);

    return 0;
}
