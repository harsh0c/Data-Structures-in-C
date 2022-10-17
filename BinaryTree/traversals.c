#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void printInorder(struct node* node){
    if(node==NULL){
        return;
    }
    printInorder(node->left);
    printf("%d ",node->data);
    printInorder(node->right);
}

void printPreorder(struct node* node){
    if(node==NULL){
        return;
    }
    printf("%d ",node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct node* node){
    if(node==NULL){
        return;
    }
    printPreorder(node->left);
    printPreorder(node->right);
    printf("%d ",node->data);
}

struct node* create(){
   struct node *temp, *root;  
   int data, choice;
   temp = (struct node *)malloc(sizeof(struct node));  
   printf("\nEnter 0 to exit or 1 for new node ");  
   scanf("%d", &choice);
   if(choice==0){
       return 0;  
    }  
    else{
       printf("Enter the data:");  
       scanf("%d", &data);  
       temp->data = data;  
       printf("\n->Enter the left child of %d", data);  
       temp->left = create();  
       printf("\n->Enter the right child of %d", data);  
       temp->right = create();  
        return temp;
    }
}
int main(){
    struct node* root=create();
    printInorder(root);
    printf("\n");
    printPreorder(root);
    printf("\n");
    printPostorder(root);
    printf("\n");

    return 0;
}