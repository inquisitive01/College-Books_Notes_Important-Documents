//insertion sort
#include<stdio.h>
void insertion_sort(int a[],int n)
{
    int i,j,item;
    for(j=1;j<=n;j++)
    {
        item=a[j];
        i=j-1;
        while(i>0 && a[i]>item)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=item;
    }
}
void main()
{
    int a[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter array elements: ");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    insertion_sort(a,n);
    printf("Sorted array: ");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
}

