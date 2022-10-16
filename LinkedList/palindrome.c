#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}*node;

// node pointer.

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
void AddAtPos(node *head,int pos,int val){
    struct Node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=temp->next;
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
void deleteAtpos(node* head,int pos){
    struct Node* temp=*head;
    struct Node* prevNode=NULL;
    for(int i=1;i<pos;i++){
        prevNode=temp;
        temp=temp->next;
    }
    prevNode->next=temp->next;
    free(temp);
}
struct Stack{
    int top;
    int* arr;
};
void push(struct Stack* st,int val){
    st->arr[++st->top]=val;
}
int pop(struct Stack* st){
    return st->arr[st->top--];
}
int isPalindrome(node head){
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->arr=(int*)malloc(10*sizeof(int));
    node temp=head;
    while(temp!=NULL){
        push(st,temp->data);
        temp=temp->next;
    }
    node comp=head;
    while(comp!=NULL){
        if(comp->data==pop(st)){
            comp=comp->next;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    // struct Node* head=NULL;
    node head=NULL;
    node tail=NULL;
    // head,tail is a pointer of type struct Node. And it points to null here.

    // CreateLL(&head,&tail,10);    // &head argument is the address head is pointing to.
    AddAtEnd(&head,&tail,1);
    AddAtEnd(&head,&tail,2);
    AddAtEnd(&head,&tail,3);
    AddAtEnd(&head,&tail,4);
    AddAtEnd(&head,&tail,1);
    // AddAtPos(&head,4,40);
    display(head);
    if(isPalindrome(head)==1){
        printf("LL is palindrome");
    }
    else{
        printf("not a palindrome");
    }
    return 0;
}