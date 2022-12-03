#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a,int b){
    return (a>b)? a: b;
}

int height(struct Node* node){
    if(node==NULL){
        return 0;
    }
    else{
        return node->height;
    }
}

int bf(struct Node* node){
    if(node==NULL){
        return 0;
    }
    return (height(node->left)-height(node->right));
}

struct Node* createnewNode(int key){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;   // leaf
    
    return newNode;
}

/*    R                 L

      y                 x                 
     /                   \
     x                   y
     \                  /
     T2                T2
*/

struct Node* rightRotation(struct Node* y){
    struct Node* x=y->left;
    struct Node* T2=x->right;
    
    // after right rotation
    x->right=y;
    y->left=T2;
    
    x->height=max(height(x->left),height(x->right)) +1; // updating height after rotation.
    y->height=max(height(y->left),height(y->right)) +1;
    
    return x;   // new root after rotation.
}
struct Node* leftRotation(struct Node* x){
    struct Node* y=x->right;
    struct Node* T2=y->left;
    
    // after left rotation
    y->left=x;
    x->right=T2;
    
    x->height=max(height(x->left),height(x->right)) +1; // updating height after rotation.
    y->height=max(height(y->left),height(y->right)) +1;
    
    return y;   // new root after rotation.
}


struct Node* insertNode(struct Node* root,int key){
    if(root==NULL){     
        return createnewNode(key);
    }
    if(key<root->data){
        root->left=insertNode(root->left,key);
    }
    else if(key>root->data){
        root->right=insertNode(root->right,key);
    }
    else{
        return root;
    }
    
    root->height=max(height(root->left),height(root->right)) + 1;   // updating height of root after insertion.
    
    int balancef=bf(root);  // checking bf.
    
    if(balancef>1 && key<root->left->data){  // LL case
        return rightRotation(root);
    }
    
    if(balancef>1 && key>root->left->data){ // LR case
        root->left=leftRotation(root->left);  // rotating root->left.
        return rightRotation(root);         // rotating root.
    }
    
    if(balancef<-1 && key>root->right->data){   // RR case
        return leftRotation(root);        
    }
    
    if(balancef<-1 && key<root->right->data){   // RL case
        root->right=rightRotation(root->right);
        return leftRotation(root);
    }
    
    return root;        // returning original root node if no rotations required.
}

void preOrder(struct Node* node){
    if(node==NULL){
        return;
    }
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    struct Node* root=NULL;
    int elem,data;
    printf("Enter total elements: ");
    scanf("%d",&elem);
    for(int i=1;i<=elem;i++){
        scanf("%d",&data);
        root=insertNode(root,data);
    }
    
    printf("Pre Order Traversal: ");
    
    preOrder(root);

    return 0;
}
