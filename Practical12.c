#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node {
    int coefficient;
    int exponent;
    struct node* next;
} Node;

Node* CreateNode(int coeff, int exp){
    Node* newnode = (Node*) calloc(1, sizeof(Node));
    if(newnode == NULL){
        fprintf(stderr, "ERROR : Memory Allocation of Node Failed");
        exit(1);
    }
    newnode->coefficient = coeff;
    newnode->exponent = exp;
    newnode->next = NULL;
    return newnode;
}

void FreePolynomial(Node* Header){
    Node* curr = Header->next;
    while(curr != NULL){
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    Header->next = NULL;
}

Node* CreatePolynomial(){
    Node* Header = CreateNode(INT_MAX, INT_MAX);
    Node* curr = Header, *newnode;
    int coeff, exp, size;
    printf("Enter No. of Terms in Polynomial : ");
    scanf("%d", &size);
    printf("Enter Polynomial Terms : \n");
    for(int i = 0; i < size; i++){
        printf("Enter Coefficient of %d term : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter Exponent of %d term : ", i + 1);
        scanf("%d", &exp);
        newnode = CreateNode(coeff, exp);
        curr->next = newnode;
        curr = newnode;
    }
    return Header;
}

void Insert(Node* Header, int coeff, int exp){
    Node* newnode = CreateNode(coeff, exp);
    Node* curr = Header;
    while(curr->next != NULL){
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
}

Node* SearchNode(Node* Header, int exp){
    Node* ptr = Header->next;
    while(ptr != NULL && ptr->exponent != exp){
        ptr = ptr->next;
    }
    return ptr;
}

Node* AddPolynomial(Node* Header1, Node* Header2){
    if(Header1->next == NULL || Header2->next == NULL){
        fprintf(stderr, "Cannot Add Polynomials as one or both of them are NULL\n");
        return NULL;
    }

    Node* AddHeader = CreateNode(INT_MAX, INT_MAX);
    Node* ptr = Header1->next;
    while(ptr != NULL){
        Node* Key = SearchNode(Header2, ptr->exponent);
        if(Key == NULL){
            Insert(AddHeader, ptr->coefficient, ptr->exponent);
        }else{
            Insert(AddHeader, ptr->coefficient + Key->coefficient, ptr->exponent);
        }
        ptr = ptr->next;
    }
    ptr = Header2->next;
    while(ptr != NULL){
        Node* Key = SearchNode(AddHeader, ptr->exponent);
        if(Key == NULL){
            Insert(AddHeader, ptr->coefficient, ptr->exponent);
        }
        ptr = ptr->next;
    }
    return AddHeader;
}

void DisplayPolynomial(Node* Header){
    Node* curr = Header->next;
    if(curr == NULL){
        printf("NULL\n");
    }else{
        while(curr->next != NULL){
            printf("%d (X^%d) + ", curr->coefficient, curr->exponent);
            curr = curr->next;
        }
        printf("%d (X^%d)", curr->coefficient, curr->exponent);
        printf("\n");
    }
}

int main(){
    printf("Enter Polynomial 1\n\n");
    Node* Pol1 = CreatePolynomial();
    printf("Enter Polynomial 2\n\n");
    Node* Pol2 = CreatePolynomial();

    Node* Add = AddPolynomial(Pol1, Pol2);

    printf("Polynomial 1 : ");
    DisplayPolynomial(Pol1);
    printf("Polynomial 2 : ");
    DisplayPolynomial(Pol2);
    printf("Polynomial 1 + Polynomial 2 : ");
    DisplayPolynomial(Add);

    FreePolynomial(Pol1);
    FreePolynomial(Pol2);
    FreePolynomial(Add);

    free(Pol1);
    free(Pol2);
    free(Add);
}