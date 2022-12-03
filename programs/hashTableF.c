#include <stdio.h>

int m;
int hashT[20];

void insert(int num,int n){
    int idx=num%m;
    if(hashT[idx]==-1){
        hashT[idx]=num;
    }
    else{
        for(int j=0;j<m;j++){
            int lprob=(idx+j)%m;
            if(hashT[lprob]==-1){
                hashT[lprob]=num;
                break;
            }
        }
    }
}

int search(int data){
    int idx=data%m;
    if(hashT[idx]==data){
        return idx;
    }
    else{
        for(int j=0;j<m;j++){
            int lprob=(idx+j)%m;
            if(hashT[lprob]==data){
                return lprob;
            }
        }
    }
    return -1;
}

void delete(int data){
    int idx=data%m;
    if(hashT[idx]==data){
        hashT[idx]=-1;
    }
    else{
        for(int j=0;j<m;j++){
            int lprob=(idx+j)%m;
            if(hashT[lprob]==data){
                hashT[lprob]=-1;
            }
        }
    }
}
void display(int n){
    for(int i=0;i<m;i++){
        if(hashT[i]==-1){
            printf("_ ");
        }
        else{
            printf("%d ",hashT[i]);
        }
    }
}


int main()
{
    int n,key,del;
    printf("Enter size of hash table: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        hashT[i]=-1;
    }
   
    int ch=0;
    int num;
   
    while(1){
        printf("Enter 0:to END , 1: to insert , 2: to search , 3: to delete\n");
        scanf("%d",&ch);
       
        if(ch==0){
            break;
        }
       
        if(ch==1){
            printf("Enter the element to be inserted: ");
            scanf("%d",&num);
            insert(num,n);
        }
        else if(ch==2){
            printf("Enter the element to be searched: ");
            scanf("%d",&key);
            int found=search(key);
            if(found==-1){
                printf("Element not present in the hash table\n");
            }
            else{
                printf("Element at index: %d\n",found);
            }
        }
        else if(ch==3){
            printf("Enter the element to be deleted: ");
            scanf("%d",&del);
            delete(del);
        }
       
    }
    display(n);
    return 0;
}
