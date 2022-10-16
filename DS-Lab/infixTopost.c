#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int top;
    unsigned capacity;
    int* arr;
};

struct Stack* CreateStack(unsigned cap){
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->capacity=cap;
    st->arr=(int*)malloc(cap* sizeof(int));
    return st;
}

void push(struct Stack* st,char op){
    st->arr[++st->top]=op;
}

int isEmpty(struct Stack* st){
    return st->top==-1;
}

char pop(struct Stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top--];
    }
    return 'E';
}

int isOperand(char ch){
    if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')){
        return 1;
    }
    return 0;
}

int precedence(char optor){
    if(optor=='+'||optor=='-'){
        return 1;
    }
    else if(optor=='*'||optor=='/'){
        return 2;
    }
    else if(optor=='^'){
        return 3;
    }
    else{
        return -1;
    }
}
char peek(struct Stack* st){
    return st->arr[st->top];
}

int infixTopostfix(char* exp){
    char pos[50];
    int i=0,k=-1;
    struct Stack* stack=CreateStack(strlen(exp));
    while(exp[i]!='\0'){
        if(isOperand(exp[i])){
            pos[++k]=exp[i];
        }
        else if(exp[i]=='('){
            push(stack,exp[i]);
        }
        else if(exp[i]==')'){
            while(!isEmpty(stack)&&peek(stack)!='('){
                pos[++k]=pop(stack);
            }
            pop(stack);
        }
        else{   // operators
            while(!isEmpty(stack) && precedence(exp[i])<=precedence(peek(stack))){
                pos[++k]=pop(stack);
            }
            push(stack,exp[i]);
        }
        pos[++k]='\0';
        printf("%s\n",pos);
        --k;
        i++;
    }
    while(!isEmpty(stack)){
        pos[++k]=pop(stack);
    }
    pos[++k]='\0';
    printf("%s",pos);
}

int main()
{
    printf("Enter the expression:");
    char exp[50];
    scanf("%s",exp);
    infixTopostfix(exp);

    return 0;
}