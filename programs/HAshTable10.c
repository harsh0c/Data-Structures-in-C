#include <stdio.h>

int m;
int hashT[20];

void insert(int arr[],int n){
    for(int i=0;i<n;i++){
        int idx=arr[i]%m;
        if(hashT[idx]==-1){
            hashT[idx]=arr[i];
        }
        else{
            for(int j=0;j<m;j++){
                int lprob=(idx+j)%m;
                if(hashT[lprob]==-1){
                    hashT[lprob]=arr[i];
                    break;
                }
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
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<m;i++){
        hashT[i]=-1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insert(arr,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    int found=search(key);
    if(found==-1){
        printf("Element not present in the hash table\n");
    }
    else{
        printf("Element at index: %d\n",found);
    }
    
    printf("Enter the element to be deleted: ");
    scanf("%d",&del);
    delete(del);
    display(n);
    return 0;
}
