#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};


int main(){
    int arr[]={3,2,9,6,11,13,7,12,22};
    int n=9;
    int m=10;
    struct node* chain[10];

    for(int i=0;i<m;i++){
        chain[i]=NULL;
    }

    for(int i=0;i<n;i++){
        int idx=arr[i]%m;
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=arr[i];
        if(chain[idx]==NULL){  
            new->next=NULL;
            chain[idx]=new;
        }
        else{
            struct node* temp1=chain[idx];
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=new;
            new->next=NULL;
        }
    }

    for(int i=0;i<m;i++){
        if(chain[i]==NULL){
            printf("_ \n");
        }
        else{
            struct node* temp=chain[i];
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
        printf("\n");
    }
}