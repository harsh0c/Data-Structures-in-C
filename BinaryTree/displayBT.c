#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

int height(struct node* node){
    if (node == NULL)
        return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        if (lHeight > rHeight){
            return (lHeight + 1);
        }
        else{
            return (rHeight + 1);
        }
    }
}

unsigned int getTerminalNodeCount(struct node* node){
    if(node == NULL)	
        return 0;
    if(node->left == NULL && node->right==NULL)	
        return 1;			
    else
        return getTerminalNodeCount(node->left) + getTerminalNodeCount(node->right);	
}

unsigned int getNonTNodecount(struct node* root){
    if (root == NULL || (root->left == NULL && root->right == NULL)){
        return 0;
    }
    return 1 + getNonTNodecount(root->left) + getNonTNodecount(root->right);
}

int count=10;
void display(struct node* root, int s){
    if (root == NULL)
    {
        return;
    }
    s=s+count;
    display(root->right,s);
    printf("\n");
    for (int i = count; i < s; i++){
        printf(" ");
    }
    printf("%d\n", root->data);
    display(root->left,s);
}


struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
struct node* insertLeft(struct node* root, int value) {
    root->left = newNode(value);
    return root->left;
}
struct node* insertRight(struct node* root, int value) {
  root->right = newNode(value);
  return root->right;
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

int main()
{
    struct node *root;
    root = create(); 
	
    printf("Height of the tree is %d\n", height(root)-1);
    printf("Terminal node count of the tree is %d\n", getTerminalNodeCount(root));
    printf("Non-Terminal node count of the tree is %d\n", getNonTNodecount(root));
    display(root,0);
    return 0;
}