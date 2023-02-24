#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int front;
    int rear;
    unsigned capacity;
    int* arr;
};

struct Queue* createQueue(unsigned capacity){
    struct Queue* qu=(struct Queue*)malloc(sizeof(struct Queue));
    qu->front=qu->rear=-1;
    qu->capacity=capacity;
    qu->arr=(int*)malloc(capacity*sizeof(int));
    return qu;
}
int isEmpty(struct Queue* q){
    if(q->front==-1 && q->rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Queue* q){
    if(q->rear==q->capacity-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q,int val){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else if(isEmpty(q)){
        q->front=q->rear=0;
        q->arr[q->rear]=val;
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}

int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        int a=q->arr[q->front];
        q->front=q->rear=-1;
        return a;
    }
    else{
        return q->arr[q->front++];
    }
}

int peek(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        return q->arr[q->front];
    }
}
void display(struct Queue* q){
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        for(int i=q->front;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }
}
int main(){
    struct Queue* qu=createQueue(5);
    enqueue(qu,10);
    enqueue(qu,20);
    enqueue(qu,30);
    enqueue(qu,40);
    enqueue(qu,50);
    // enqueue(qu,60);

    dequeue(qu);
    enqueue(qu,60);
    display(qu);

}