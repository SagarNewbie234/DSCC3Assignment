#include <stdio.h>
#include <ctype.h>

int evaluatePostfix(char* postfix){
    int stack[32], tempA, tempB, top = -1;
    char* read = postfix;
    while(*read != '\0'){
        if(isdigit(*read)){
            int num = 0;
            while(isdigit(*read)){
                num = num*10 + (*read - 48);
                read++;
            }
            read--;
            stack[++top] = num;
        }else{
            switch(*read){
                case '+':
                    tempB = stack[top--];
                    tempA = stack[top--];
                    stack[++top] = tempA + tempB;
                    break;
                case '-':
                    tempB = stack[top--];
                    tempA = stack[top--];
                    stack[++top] = tempA - tempB;
                    break;
                case '*':
                    tempB = stack[top--];
                    tempA = stack[top--];
                    stack[++top] = tempA * tempB;
                    break;
                case '/':
                    tempB = stack[top--];
                    tempA = stack[top--];
                    stack[++top] = tempA / tempB;
                    break;
                default:
            }
        }
        read++;
    }
    return stack[top];
}

int main(){
    char expression[100];
    printf("Enter Postfix Expression : ");
    scanf("%[^\n]s", expression);
    int result = evaluatePostfix(expression);
    printf("Result : %d\n", result);
}