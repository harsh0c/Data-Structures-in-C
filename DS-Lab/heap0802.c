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
    int smallest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] < arr[smallest])
        smallest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] < arr[smallest])
        smallest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, smallest);
    }
}

void buildHeap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr,n, i);
    
    printArray(arr,n);
}
void deleteRoot(int arr[], int* n)
{
    // Get the last element
    int lastElement = arr[*n - 1];
    printf("%d\n",arr[0]);
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    *n = *n - 1;
 
    // heapify the root node
    heapify(arr, *n, 0);
}

void heapSort(int arr[], int N){
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}


int main(){
    int arr[]={ 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr,n);
    deleteRoot(arr,&n);
    printArray(arr,n);
    heapSort(arr,n);
    printf("Sorted array is\n");
    printArray(arr,n);
    return 0;
}