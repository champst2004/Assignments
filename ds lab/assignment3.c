#include<stdio.h>
#define max 20

char stack[max];
int top = -1;

void push(char c){
    top++;
    stack[top] = c;
}

char pop(){
    char temp = stack[top];
    top--;
    return temp;
}

char peek(){
    return stack[top];
}

int precedance(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else{
        return 0;
    }
}

int isOperand(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
}

void convertExp(char infix[], char postfix[]){
    int inf = 0, post = 0;
    char ch;
    while(infix[inf] != '\0'){
        ch = infix[inf];
        
        if(isOperand(ch)){
            postfix[post] = ch;
            post++;
        }

        else if(ch == '('){
            push(ch);
        }
        
        else if(ch == ')'){
            while(peek() != '('){
                char temp = pop();
                postfix[post] = temp;
                post++;
            }
            pop();
        }
        else{
            while(top != -1 && precedance(peek()) >= precedance(ch)){
                char temp = pop();
                postfix[post] = temp;
                post++;
            }
            push(ch);
        }
        inf++;
    }
    while(top != -1){
        char temp = pop();
        postfix[post] = temp;
        post++;
    }
    postfix[post] = '\0';
}

int main()
{
    char infix[max], postfix[max];
    printf("Enter infix expression: ");
    scanf("%s", &infix);
    convertExp(infix, postfix);
    printf("The postfix expression is: %s", postfix);
    return 0;
}