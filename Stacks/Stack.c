#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    unsigned capacity;
    int *arr;
};

struct Stack* createStack(unsigned capacity){
    struct Stack *st=(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->capacity=capacity;
    st->arr=(int*)malloc(capacity*sizeof(int));
    return st;
}
int isFull(struct Stack *st){
    return (st->capacity-1==st->top);
}
int isEmpty(struct Stack *st){
    return st->top==-1;
}
void push(struct Stack *st,int val){
    if(isFull(st)){
        printf("Stack overflow\n");
        // return;
    }
    else{
        st->top++;
        st->arr[st->top]=val;
    }
}
int pop(struct Stack *st){
    if(isEmpty(st)){
        printf("Stack is Empty\n");
    }
    else{
        int a=st->arr[st->top];
        st->top--;
        return a;
    }
}
void display(struct Stack *st){
    for(int i=0;i<=st->top;i++){
        printf("%d ",st->arr[i]);
    }
    printf("\n");
}
int main(){
    struct Stack* stack=createStack(3);
    pop(stack);
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    pop(stack);
    pop(stack);
    push(stack,13);
    display(stack);

    return 0;
}