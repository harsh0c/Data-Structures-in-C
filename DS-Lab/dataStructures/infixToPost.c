#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Stack{
    int top;
    unsigned capacity;
    char* arr;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->capacity=capacity;
    st->arr=(char*)malloc(capacity*sizeof(int));
    return st;
}
int isFull(struct Stack* st){
    if(st->top==st->capacity-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack* st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct Stack* st,char val){
    if(isFull(st)){
        printf("Stack Overflow\n");
    }
    else{
        st->arr[++st->top]=val;
    }
}

char pop(struct Stack* st){
    if(isEmpty(st)){
        return '0';
    }
    else{
        return st->arr[st->top--];
    }
}

int operation(int v1,int v2,char optor){
    if(optor=='+'){
        return v1+v2;
    }
    else if(optor=='-'){
        return v1-v2;
    }
    else if(optor=='*'){
        return v1*v2;
    }
    else if(optor=='/'){
        return v1/v2;
    }
    else if(optor=='^'){
        return pow(v1,v2);
    }
}

int postfixEval(char* exp){
    int l=strlen(exp);
    struct Stack* st=createStack(l);
    for(int i=0;i<l;i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^'){
            char op1=pop(st);
            char op2=pop(st);
            int val=operation(op2-'0',op1-'0',exp[i]);
            push(st,val);
        }
        else{
            push(st,exp[i]);
        }
    }
    return pop(st);
}

int main(){
    char exp[50];
    printf("Enter postfix expression: ");
    scanf("%s",exp);
    int ans=postfixEval(exp);
    printf("%d\n",ans);

    return 0;
}