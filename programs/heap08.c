#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i){
    int largeNode = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largeNode])
        largeNode = left;
    if (right < N && arr[right] > arr[largeNode])
        largeNode = right;
    
    if (largeNode != i) {
        swap(&arr[i], &arr[largeNode]);
        heapify(arr, N, largeNode);
    }
}

void buildHeap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr,n, i);
    
    printArray(arr,n);
}
void deleteRoot(int arr[], int* n)
{
    int lastElement = arr[*n - 1];
    printf("%d\n",arr[0]);
    arr[0] = lastElement;
    *n = *n - 1;
    heapify(arr, *n, 0);
}

void heapSort(int arr[], int N){
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
        
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int kthlargest(int arr[],int n,int k){
    if(k<=n){
        return arr[n-k];
    }
}


int main(){
    int n;
    printf("Enter total elements for creating max-heap: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Level Order Trvaersal of Tree\n");
    buildHeap(arr,n);
    printf("Deleted root node which is the largest element ");
    deleteRoot(arr,&n);
    printArray(arr,n);
    heapSort(arr,n);
    printf("Heap Sort:\n");
    printf("Sorted array is\n");
    printArray(arr,n);
    // 3 largest element
    int k=3;
    printf("%d largest element is: %d",k,kthlargest(arr,n,3));
    return 0;
}