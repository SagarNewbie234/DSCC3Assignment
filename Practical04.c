#include <stdio.h>

void ExpressionBalanceChecker(const char* string){
    char stack[100], open;
    int top = -1;

    for(int i = 0; string[i] != '\0'; i++){
        char c = string[i];
        int unbalanced = 0;
        switch(c){
            case '(':
            case '{':
            case '[':
                top++;
                stack[top] = c;
                break;
            case ')':
                open = stack[top--];
                if(open != '(') unbalanced = 1;
                break;
            case '}':
                open = stack[top--];
                if(open != '{') unbalanced = 1;
                break;
            case ']':
                open = stack[top--];
                if(open != '[') unbalanced = 1;
                break;
            default:
                printf("Error : Invalid character Encountered, Cannot determine balance!\n");
                return;
        }

        if(unbalanced){
            printf("Result : Brackets are not balanced\n");
            return;
        }
    }

    if(top != -1){
        printf("Result : Brackets are not balanced!\n");
    }else{
        printf("Result : The Brackets are balanced!\n");
    }
}

int main(){
    char buffer[100];
    printf("**********Bracket Checker*********");
    printf("Input a string containing Brackets and check if its balanced or not :\nEnter String : ");
    scanf("%[^\n]s", buffer);

    ExpressionBalanceChecker(buffer);
}