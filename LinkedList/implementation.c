#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head,*tail;


void CreateLL(int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    head=tail=new;
}
void AddAtEnd(int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        head=tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}
void AddAtFirst(int val){
    if(head==NULL){
        CreateLL(val);
    }
    else{
        struct Node* new=(struct Node*)malloc(sizeof(struct Node));
        new->data=val;
        new->next=head;
        head=new;
    }
}
void AddAtPos(int pos,int val){
    struct Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=temp->next;
    temp->next=new;
}
void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteFirstNode(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->next==NULL){
        head=tail=NULL;
    }
    else{
        struct Node* temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteLastNode(){
    struct Node* temp=head;
    struct Node* prevNode=NULL;
    while(temp->next!=NULL){
        prevNode=temp;
        temp=temp->next;
    }
    free(temp);
    prevNode->next=NULL;
    tail=prevNode;
}
void deleteAtpos(int pos){
    struct Node* temp=head;
    struct Node* prevNode=NULL;
    for(int i=1;i<pos;i++){
        prevNode=temp;
        temp=temp->next;
    }
    prevNode->next=temp->next;
    free(temp);
}

int main(){
    head=NULL;
    CreateLL(10);
    AddAtEnd(20);
    AddAtEnd(30);
    AddAtEnd(50);
    AddAtPos(4,40);
    display();
    deleteFirstNode();
    deleteLastNode();
    deleteAtpos(2);
    display();
    return 0;
}