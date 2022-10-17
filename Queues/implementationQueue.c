#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int rear;
    int size;
    unsigned capacity;
    int* arr;
};
int isFull(struct Queue* q){
    if(q->size==q->capacity){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue* q){
    if(q->size==0){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue* q,int val){
    
    if(isFull(q)){
        printf("Queue is full\n");
        // return;
    }
    else{
        q->rear=(q->front + q->size) % q->capacity;
        q->arr[q->rear]=val;
        q->size++;
    }
    
}

int dequeue(struct Queue* q){
    
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    
    else{
        int val=q->arr[q->front];
        q->front=(q->front+1) % q->capacity;
        q->size--;
        return val;
    }
    
}
void display(struct Queue* q){
    for(int i=0;i<q->size;i++){
        int idx=(q->front+i) % q->capacity;
        printf("%d ",q->arr[idx]);
    }
    printf("\n");
}

int main(){
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->front=0;
    queue->rear=-1;
    queue->size=0;
    queue->capacity=5;
    queue->arr=(int*)malloc(queue->capacity*sizeof(int));
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    dequeue(queue);    // 10 out
    
    enqueue(queue,50);
    enqueue(queue,60);
    enqueue(queue,70);
    display(queue);
    return 0;
}