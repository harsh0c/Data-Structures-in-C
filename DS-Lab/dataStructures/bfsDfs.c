#include <stdio.h>
#include <stdlib.h>

int a[20][20],vis[20],stack[20],queue[20],top=-1,f=-1,r=-1;

void enqueue(int data){
    if(r==19){
        return;
    }
    else if(r==-1&&f==-1){
        f++;
        r++;
        queue[r]=data;
    }
    else{
        r++;
        queue[r]=data;
    }
}
int dequeue(){
    if(f==-1 && r==-1){
        return 0;
    }
    else if(f==r){
        int a=queue[r];
        f=r=-1;
        return a;
    }
    else{
        return queue[f++];
    }
}

void bfs(int src,int n){
    enqueue(src);
    vis[src]=1;
    int p=dequeue();
    if(p!=0){
        printf("%d ",p);
    }
    while(p!=0){
        for(int i=1;i<=n;i++){
            if(a[p][i]!=0 && vis[i]==0){
                enqueue(i);
                vis[i]=1;
            }
        }
        p=dequeue();
        if(p!=0){
            printf("%d ",p);
        }

    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bfs(i,n);
        }
    }
}

void push(int data){
    if(top==19){
        return;
    }
    else{
        top++;
        stack[top]=data;
    }
}
int pop(){
    if(top==-1){
        return 0;
    }
    else{
        int a=stack[top];
        top--;
        return a;
    }
}
int peek(){
    if(top==-1){
        return 0;
    }
    else{
        int a=stack[top];
        return a;
    }
}

void dfs(int s,int n){
    push(s);
    vis[s]=1;
    printf("%d ",s);
    while(1){
        int i;
        for(i=1;i<=n;i++){
            if(a[s][i]!=0 && vis[i]==0){
                push(i);
                vis[i]=1;
                printf("%d ",i);
                s=i;
                i=1;
                break;
            }
        }
        if(i!=1){
            int k=pop();
            if(k==0){
                break;
            }
            s=peek();
            i=1;
        }
    }
}


int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("Enter 1 if there is node from %d to %d else 0 ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The adjacency matrix is\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    while(1){
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
        int ch;
        printf("Enter 1 to continue, 0 to exit: ");
        scanf("%d",&ch);
        if(ch==0){
            break;
        }
        
        else{
            int choice,s;
            printf("1:BFS\n2:DFS ");
            scanf("%d",&choice);
            printf("Enter source vertex: ");
            scanf("%d",&s);
            if(choice==1){
                bfs(s,n);
                printf("\n");
            }
            else if(choice==2){
                dfs(s,n);
            }
        }
    }
}