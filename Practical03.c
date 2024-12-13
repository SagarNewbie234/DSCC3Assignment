#include <stdio.h>
#define MAX 5

typedef struct stack{
    int stack[MAX];
    int top;
} Stack;

Stack CreateStack(){
    Stack s;
    s.top = -1;
    return s;
}

void Push(Stack* s, int data){
    if(s->top == MAX - 1){
        printf("Stack Overflow\n\n");
        return;
    }
    s->top++;
    s->stack[s->top] = data;
}

int Pop(Stack* s){
    if(s->top == -1){
        printf("Stack Underflow\n\n");
        return -1;
    }
    return s->stack[s->top--];
}

void Display(Stack* s){
    if(s->top == -1){
        printf("|Empty|\n\n");
    }else{
        printf("|%4d| <- TOP\n", s->stack[s->top]);
        for(int i = s->top - 1; i >= 0; i--){
            printf("|%4d|\n", s->stack[i]);
        }
        printf("------\n\n");
    }
}

int main(){
    Stack stack = CreateStack();

    Push(&stack, 10);
    Display(&stack);
    Push(&stack, 20);
    Display(&stack);
    Push(&stack, 30);
    Display(&stack);
    Push(&stack, 40);
    Display(&stack);
    Push(&stack, 50);
    Display(&stack);

    Push(&stack, 60);

    printf("Popped Element : %d\n",  Pop(&stack));
    Display(&stack);
    printf("Popped Element : %d\n",  Pop(&stack));
    Display(&stack);
    printf("Popped Element : %d\n",  Pop(&stack));
    Display(&stack);
    printf("Popped Element : %d\n",  Pop(&stack));
    Display(&stack);
    printf("Popped Element : %d\n",  Pop(&stack));
    Display(&stack);
    Pop(&stack);
    Display(&stack);
}