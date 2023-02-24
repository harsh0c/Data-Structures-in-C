#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(){
    int ch;
    printf("\nEnter 0 to exit or 1 for new node ");
    scanf("%d",&ch);
    if(ch==1){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&temp->data);
        printf("enter left node of %d: ",temp->data);
        temp->left=createnode();
        printf("enter right node of %d: ",temp->data);
        temp->right=createnode();
        return temp;
    }
    else{
        return 0;
    }
}
int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight){
            return 1+lheight;
        }
        else{
            return 1+rheight;
        }
    }
}
void printCurrentlvl(struct node* root,int i){
    if(root==NULL){
        return;
    }
    else if(i==1){
        printf("%d ",root->data);
    }
    else{
        printCurrentlvl(root->left,i-1);
        printCurrentlvl(root->right,i-1);
    }
}
void levelorder(struct node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printCurrentlvl(root,i);
        printf("\n");
    }
}

int main(){
    struct node* root=createnode();
    levelorder(root);
} 