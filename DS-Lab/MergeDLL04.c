#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void linkedListTraversal(struct Node *head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void addAtEnd(struct Node** head,struct Node** tail){
    struct Node* new = (struct Node *) malloc(sizeof(struct Node));
    int value;
    printf("enter value to be inserted in linked list");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    if(*head==NULL){
        new->prev=NULL;
        *head=new;
        *tail=new;
    }
    else{
        struct Node* temp=*head;
        struct Node* prevnode;
        while(temp->next!=NULL){
            prevnode=temp;
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
        *tail=new;
    }
}

void merge(struct Node** head1,struct Node** tail1,struct Node** head2,struct Node** tail2){
    struct Node* temp=*tail1;
    temp->next = *head2;
}

void sortMergedList(struct Node** head1){
    struct Node* temp=*head1;
    while(temp!=NULL){  // selection sort.
        struct Node* temp2=temp;
        int min=temp->data;
        struct Node* Nextnode=temp->next;
        while(Nextnode!=NULL){
            if(Nextnode->data < min){
                min=Nextnode->data;
                temp2=Nextnode;
            }
            Nextnode=Nextnode->next;
        }
        int tempvar;
        tempvar=temp->data;
        temp->data=min;
        temp2->data=tempvar;
        
        temp=temp->next;
    }
}
 
int main(){

    char ch;
    struct Node* head1=NULL;
    struct Node* tail1=NULL;
    struct Node* head2=NULL;
    struct Node* tail2=NULL;
    printf("creating a sorted doubly linked list-1\n");
    while(1){
        printf("y - continue, n - exit");
        scanf(" %c",&ch);
        if(ch=='n'){
            break;
        }
        else{
            addAtEnd(&head1,&tail1);
        }
    }
    printf("creating a sorted doubly linked list-2\n");
    while(1){
        printf("y - continue, n - exit");
        scanf(" %c",&ch);
        if(ch=='n'){
            break;
        }
        else{
            addAtEnd(&head2,&tail2);
        }
    }
    printf("Linked list-1 \n"); 
    linkedListTraversal(head1);
    sortMergedList(&head1);
    printf("Sorted Linked list-1 \n"); 
    linkedListTraversal(head1);
    
    printf("Linked list-2 \n"); 
    linkedListTraversal(head2);
    printf("Sorted Linked list-2 \n"); 
    sortMergedList(&head2);
    linkedListTraversal(head2);
    
    merge(&head1,&tail1,&head2,&tail2);
    printf("merged doubly Linked list \n");
    linkedListTraversal(head1);
    
    sortMergedList(&head1);
    printf("Merged Sorted doubly Linked list \n");
    linkedListTraversal(head1);
    return 0; 
}