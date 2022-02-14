//heap sort
#include<stdio.h> 
int temp; 

void heapify(int arr[], int size, int i) 
{ 
    int largest = i;   
    int left = 2*i;   
    int right = 2*i;   

    if (left < size && arr[left] >arr[largest]) 
        largest = left; 

    if (right < size && arr[right] > arr[largest]) 
        largest = right; 

    if (largest != i) 
    { 
        temp = arr[i]; 
        arr[i]= arr[largest];   
        arr[largest] = temp; 
        heapify(arr, size, largest); 
    } 
} 

void heapSort(int arr[], int size) 
{ 
    int i; 
    for (i=size/2;i>=1;i--) 
        heapify(arr,size,i); 
    for (i=size;i>=1;i--) 
    { 
        temp = arr[1]; 
        arr[1]= arr[i];   
        arr[i] = temp; 
        heapify(arr,i,1); 
    } 
} 

void main() 
{ 
    int arr[100],n,i;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    printf("\nEnter the array elements: ");
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    heapSort(arr, n); 

    printf("printing sorted elements\n"); 
    for (i=1; i<=n; ++i) 
        printf("%d\n",arr[i]); 
}

