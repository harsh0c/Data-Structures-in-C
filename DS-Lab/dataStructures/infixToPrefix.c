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
void push(struct Stack* st,char ch){
    if(isFull(st)){
        printf("Stack Overflow\n");
    }
    else{
        st->arr[++st->top]=ch;
    }
}

char pop(struct Stack* st){
    if(isEmpty(st)){
        return 'e';
    }
    else{
        return st->arr[st->top--];
    }
}
char peek(struct Stack* st){
    if(isEmpty(st)){
        return 'e';
    }
    else{
        return st->arr[st->top];
    }
}

int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    return 3;
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

int prefixeval(char* pre){
 
    int l=strlen(pre);
    struct Stack* st=createStack(l);
    for(int i=l-1;i>=0;i--){
        if(pre[i]=='+' || pre[i]=='-' || pre[i]=='*' || pre[i]=='/'||pre[i]=='^'){
            char op1=pop(st);
            char op2=pop(st);
            int ans=operation(op1-'0',op2-'0',pre[i]);
            push(st,ans);
        }
        else{
            push(st,pre[i]);
        }
    }
    return pop(st);
}

void inToPrefix(char* exp){
    struct Stack* st=createStack(strlen(exp));
    char prefix[50];
    int i=0,k=-1;
    
    while(exp[i]!='\0'){
        if(exp[i]==')'){
            push(st,exp[i]);
        }
        else if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A'&& exp[i]<='Z')){
            prefix[++k]=exp[i];
        }
        else if(exp[i]=='('){
            while(!isEmpty(st) && peek(st)!=')'){
                prefix[++k]=pop(st);
            }
            pop(st);
        }
        else{       //operators
            while(!isEmpty(st) && precedence(exp[i])<precedence(peek(st))){
                prefix[++k]=pop(st);
            }
            push(st,exp[i]);
        }
        i++;

    }
    while(!isEmpty(st)){
        prefix[++k]=pop(st);
    }
    prefix[++k]='\0';
    strrev(prefix);     // final ans reverse again.
    printf("%s",prefix);
    int eval=prefixeval(prefix);
    printf("Ans:%d\n",eval);
}

int main(){
    char exp[50];
    printf("Enter the expression: ");
    scanf("%s",exp);
    // strrev(exp);
    int l=strlen(exp);
    for(int i=0;i<l/2;i++){     // reverse exp for prefix.
        char temp=exp[i];
        exp[i]=exp[l-i-1];
        exp[l-i-1]=temp;
    }

    // printf("%s\n",exp);
    inToPrefix(exp);
    return 0;
}