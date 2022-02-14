//linear search
#include <stdio.h>
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
// Driver code
int main(void)
{
    int i,a[20],n,x,result;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    printf("\nEnter the array elements: ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be searched: ");
    scanf("%d",&x);
    // Function call
    result = search(a, n, x);
    if(result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}

