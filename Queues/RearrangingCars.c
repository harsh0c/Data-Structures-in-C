#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if((q->r==q->f)){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
        for (int i = q->f; i< q->r; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->r--;
        q->f=-1;
    }
    return a;
}

int peek(struct queue *q){
    if(isEmpty(q)){
        return 100;
    }
    int a = q->arr[q->r];
    return a;
}
int frontPeek(struct queue *q){
    if(isEmpty(q)){
        return 100;
    }
    int front=q->f;
    front++;
    int a = q->arr[front];
    return a;
}
 
int main(){
    
    struct queue hTrack1;   // hTrack1
    hTrack1.size = 9;
    hTrack1.f = hTrack1.r = -1;
    hTrack1.arr = (int*) malloc(hTrack1.size*sizeof(int));
    struct queue hTrack2;   // hTrack2
    hTrack2.size = 9;
    hTrack2.f = hTrack2.r = -1;
    hTrack2.arr = (int*) malloc(hTrack2.size*sizeof(int));
    struct queue hTrack3;  // hTrack3
    hTrack3.size = 9;
    hTrack3.f = hTrack3.r = -1;
    hTrack3.arr = (int*) malloc(hTrack3.size*sizeof(int));

    struct queue ans;  // ans
    ans.size = 9;
    ans.f = ans.r = -1;
    ans.arr = (int*) malloc(ans.size*sizeof(int));
    int a[9];
    printf("Enter the sequence\n");
    for(int i=0;i<9;i++){
        scanf("%d",&a[i]);
    }
    // Valid for 3 towers..
    int st=1;
    for(int i=8;i>=0;i--){
        int num=a[i];
        if(st==num){
            enqueue(&ans,num);
            st++;
        }
        else{
            if(isEmpty(&hTrack1)||num>peek(&hTrack1)){
                enqueue(&hTrack1,num);
            }
            else if(isEmpty(&hTrack2)||num>peek(&hTrack2)){
                enqueue(&hTrack2,num);
            }
            else if(isEmpty(&hTrack3)||num>peek(&hTrack3)){
                enqueue(&hTrack3,num);
            }
            
        }
    }
    while(st<=9){
        int one=frontPeek(&hTrack1);
        int two=frontPeek(&hTrack2);
        int three=frontPeek(&hTrack3);

        if(one<two){
            if(one<three){
                int min=dequeue(&hTrack1);
                enqueue(&ans,min);
                st++;
            }
            else{
                int min=dequeue(&hTrack3);
                enqueue(&ans,min);
                st++;
            }
        }
        else if(two<one){
            if(two<three){
               int min=dequeue(&hTrack2);
               enqueue(&ans,min);
               st++; 
            }
            else{
                int min=dequeue(&hTrack3);
                enqueue(&ans,min);
                st++;
            }
        }
        
    }

    for(int i=0;i<9;i++){
        printf("%d",dequeue(&ans));
    }
    return 0;
}