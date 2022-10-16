#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int pow;
    struct Node* next;
}*node;

// node pointer.

void CreateLL(node* head,node* tail,int val,int pow){    // Here head is the formal argument which points to &head..
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->pow=pow;
    new->next=NULL;
    *head=*tail=new;       // &head,&tail now has pointer new.
}
void AddAtEnd(node* head,node* tail,int val,int pow){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->pow=pow;
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

node polyAdd(node poly1,node poly2){
    node res=NULL;
    node restail=NULL;
    int carry=0;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->pow == poly2->pow){
            int sum=(carry + poly1->data + poly2->data)%10;
            AddAtEnd(&res,&restail,sum,poly1->pow);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->pow > poly2->pow){
            AddAtEnd(&res,&restail,poly1->data,poly1->pow);
            poly1=poly1->next;
        }
        else if(poly2->pow > poly1->pow){
            AddAtEnd(&res,&restail,poly2->data,poly2->pow);
            poly2=poly2->next;
        }
    }
    return res;
}

int main(){
    // struct Node* head=NULL;
    node polyhead1=NULL;
    node polyTail1=NULL;

    node polyhead2=NULL;
    node polyTail2=NULL;

    // node res=NULL;
    // node resTail=NULL;
    // head,tail is a pointer of type struct Node. And it points to null here.

    CreateLL(&polyhead1,&polyTail1,5,2);    // &head argument is the address head is pointing to.
    AddAtEnd(&polyhead1,&polyTail1,4,1);
    AddAtEnd(&polyhead1,&polyTail1,2,0);
    display(polyhead1);

    // AddAtEnd(&polyhead2,&polyTail2,0,0);
    CreateLL(&polyhead2,&polyTail2,0,2);
    AddAtEnd(&polyhead2,&polyTail2,5,1);
    AddAtEnd(&polyhead2,&polyTail2,-5,0);
    display(polyhead2);

    node res=polyAdd(polyhead1,polyhead2);
    display(res);

    return 0;
}