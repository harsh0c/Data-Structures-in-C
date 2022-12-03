#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* left;
    struct Node* right;
};

struct Stack{
    int top;
    unsigned capacity;
    struct Node** arr;  // arr pointer to array of node pointers.
};

int isEmpty(struct Stack* st){
    return st->top==-1;
}
void push(struct Stack* st,struct Node* oprand){
    st->arr[++st->top]=oprand;
}
struct Node* pop(struct Stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top--];
    }
    return NULL;
}

void postorder(struct Node* node){
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c ",node->data);
}

struct Node* constructExp(char* post){
    int len=strlen(post);
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->capacity=len;
    st->arr=(struct Node**)malloc(len*sizeof(struct Node));

    for(int i=0;post[i]!='\0';i++){
       
        if((post[i]>='1'&&post[i]<='9')||(post[i]>='a'&&post[i]<='z')){
            struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
            temp->data=post[i];
            temp->left=NULL;
            temp->right=NULL;
            push(st,temp);
        }
        else{
            struct Node* optor=(struct Node*)malloc(sizeof(struct Node));
            optor->data=post[i];
            optor->right=pop(st);
            optor->left=pop(st);
            push(st,optor);
        }
    }
    struct Node* root=pop(st);
    return root;

}

int evaluateExp(struct Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        int val=(root->data) - '0';
        return val;
    }
    int lx=evaluateExp(root->left);
    int rx=evaluateExp(root->right);

    if(root->data=='+'){
        return lx+rx;
    }
    else if(root->data=='-'){
        return lx-rx;
    }
    else if(root->data=='*'){
        return lx*rx;
    }
    else{
        return lx/rx;
    }
   
}

int main(){
    char post[50];
    printf("Enter postfix expression: ");
    scanf("%s",post);
    // ab*c/ef/g*+k+xy*-
    // 15-5*27/+
    // 264*8/+3-
    struct Node* root=constructExp(post);
    postorder(root);
    printf("\nResult: %d",evaluateExp(root));
    return 0;
}
