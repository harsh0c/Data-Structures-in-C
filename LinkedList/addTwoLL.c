#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}*node;

// node pointer.
// CreteLL,AddAtEnd,AddAtFirst,AddAtPos,display,deleteFirstNode,deleteLastNode,deleteAtPos.


/* Utility Functions*/
void CreateLL(node* head,node* tail,int val){    // Here head is the formal argument which points to &head..
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    *head=*tail=new;       // &head,&tail now has pointer new.
}
void AddAtEnd(node* head,node* tail,int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
    }
    else{
        node temp=*tail;
        temp->next=new;
        *tail=new;
    }
}
void AddAtFirst(node *head,int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=*head;
    *head=new;
}
void AddAtPos(node *head,node* tail,int pos,int val){
    struct Node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=temp->next;
    if(temp->next==NULL){
        *tail=new;
    }
    temp->next=new;
}
void display(node head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteFirstNode(node* head,node* tail){
    if(*head==NULL){
        printf("List is empty\n");
    }
    else if((*head)->next==NULL){
        *head=*tail=NULL;
    }
    else{
        struct Node* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void deleteLastNode(node* head,node* tail){
    struct Node* temp=*head;
    struct Node* prevNode=NULL;
    while(temp->next!=NULL){
        prevNode=temp;
        temp=temp->next;
    }
    free(temp);
    prevNode->next=NULL;
    *tail=prevNode;
}
void deleteAtPos(node* head,int pos){
    struct Node* temp=*head;
    struct Node* prevNode=NULL;
    for(int i=1;i<pos;i++){
        prevNode=temp;
        temp=temp->next;
    }
    prevNode->next=temp->next;
    free(temp);
}
/*  */
int addLlHelper(node temp){
    if(temp->next==NULL){
        return temp->data;
    }
    int num=addLLHelper(temp->next);
    return num;
}

void addLL(node head1){
    node temp=head1;
    int one=addLLHelper(temp);
}


int main(){
    // struct Node* head=NULL;
    node head=NULL;
    node tail=NULL;
    // head,tail is a pointer of type struct Node. And it points to null here.


    // CreateLL(&head,&tail,10);    // &head argument is the address head is pointing to.
    AddAtEnd(&head,&tail,20);
    AddAtEnd(&head,&tail,30);
    AddAtEnd(&head,&tail,50);
    AddAtPos(&head,&tail,4,40);
    printf("%d ",tail->data);
    display(head);
    return 0;
}