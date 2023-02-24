#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void createLL(struct node** head,struct node** tail,int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    *head=*tail=new;
}

void addAtend(struct node** head,struct node** tail,int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
    }
    else{
        new->prev=*tail;
        *tail=new;
    }
}
