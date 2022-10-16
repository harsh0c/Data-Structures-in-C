#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head,*tail;

void createLL(int val){
    if(head==NULL){
       struct Node* new=(struct Node*)malloc(sizeof(struct Node));
       new->data=val;
       new->next=NULL;
       head=tail=new;
    }
}
void addLast(int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
       struct Node* new=(struct Node*)malloc(sizeof(struct Node));
       new->data=val;
       new->next=NULL;
       head=tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}

void deleteAtPOS(int pos){
    struct Node* temp=head;
    struct Node* nextnode=NULL;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    
    nextnode=temp->next;
    // printf("delete: %d\n",nextnode->data);
    temp->next=nextnode->next;
    free(nextnode);
}

void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteDuplicates(){
    struct Node* temp=head;
    struct Node* nextNode=head->next;
    int pos=2;
    while(temp->next!=NULL && nextNode->next!=NULL){
        while(nextNode!=NULL && temp->data==nextNode->data){
            nextNode=nextNode->next;
            deleteAtPOS(pos);
        }
        pos++;
        
        if(temp->next!=NULL && nextNode->next!=NULL){
            temp=temp->next;
            nextNode=nextNode->next;
        }   
    }
    if(temp->next!=NULL && temp->data==nextNode->data){
        temp->next=NULL;
    }
}

int main()
{
    head=NULL;
    char ch;
    
    while(1){
        printf("Enter y-to continue or n-to exit: ");
        scanf(" %c",&ch);
        if(ch=='n'){
            break;
        }
        else{
            int val;
            printf("Enter value: ");
            scanf("%d",&val);
            addLast(val);
        }
    }
    
    display();
    deleteDuplicates();
    display();

    return 0;
}