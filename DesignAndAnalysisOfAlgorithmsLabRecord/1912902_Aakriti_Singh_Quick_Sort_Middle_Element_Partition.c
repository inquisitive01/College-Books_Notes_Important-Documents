            //QUICK SORT PROGRAM---USING MIDDLE ELEMENT AS PARTITION
           //Made By Aakriti Singh Roll No.-1912902
#include<stdio.h>
void quick_sort(int a[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = a[(left + right) / 2];
      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quick_sort(a, left, j);
      if (i < right)
            quick_sort(a, i, right);
}
int main()
{
    int a[20],i,n;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array: ");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("\nArray initially: ");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
    quick_sort(a,1,n);
    printf("\nArray after sorting: ");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
    return 0;
}
