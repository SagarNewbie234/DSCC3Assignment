#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOneOf(char predicate, char* options){
    for(int i = 0; i < strlen(options); i++){
        if(predicate == options[i]) return 1;
    }
    return 0;
}

int getPriority(char operator){
    switch(operator){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void convertToPostfix(char* expression){
    int size = strlen(expression), top = -1;
    char buffer[size], *temp = expression, *write = buffer, stack[64];
    stack[0] = '\0';
    while(*temp != '\0'){
        if(*temp == '('){
            stack[++top] = *temp;
        }else if(isalnum(*temp)){
            *write = *temp;
            write++;
        }else if(*temp == ')'){
            while(stack[top] != '('){
                *write = stack[top--];
                write++;
            }
            top--;
        }else if(isOneOf(*temp, "+-/^*")){
            while(top >= 0 && stack[top] != '(' && ((getPriority(stack[top]) > getPriority(*temp)) || \
            (getPriority(stack[top]) == getPriority(*temp) && *temp != '^'))){
                *write = stack[top--];
                write++;
            }
            stack[++top] = *temp;
        }
        temp++;
    }

    while(top >= 0){
        *write = stack[top--];
        write++;
    }

    *write = '\0';
    strcpy(expression, buffer);
}

int main(){
    char expression[100];
    printf("Enter Infix Expression : ");
    scanf("%[^\n]s", expression);
    convertToPostfix(expression);
    printf("Postfix Expression is : %s\n", expression);
}