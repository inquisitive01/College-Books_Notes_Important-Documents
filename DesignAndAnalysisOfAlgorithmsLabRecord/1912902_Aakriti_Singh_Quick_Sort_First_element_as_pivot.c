//Quicksort program using first element as pivot
// Made by-Aakriti Singh 
//Roll no-1912902

#include<stdio.h>
// Partition function using first element as pivot
int Partition(int a[20], int p, int r)
{ int i,j,x,temp;
x=a[p];  i=p;
for(j=p+1;j<=r;j++)
{
 if(a[j]<=x)
 {  i=i+1;
    if(i!=j)
    {
    temp=a[i];  a[i]=a[j];  a[j]=temp;
}
 }
}
temp=a[i]; a[i]=a[p]; a[p]=temp;
return (i);
}

// Quicksort function
void Quicksort(int a[20], int p, int r)
{ int q;
  if(p<r)
  {
  q=Partition(a,p,r);
  Quicksort(a,p,q-1);
  Quicksort(a,q+1,r);
}
}

// Main function
int main()
{
int a[20],n,i;
printf("\n Enter the size of array:"); scanf("%d",&n);
printf("\n Enter %d elements \n",n);
for(i=0;i<n;i++) scanf("%d",&a[i]);
printf("\n Array elements are:\n");
for(i=0;i<n;i++) printf("%d\t",a[i]);
Quicksort(a,0,n-1);
printf("\n Sorted Array elements are\n");
for(i=0;i<n;i++) printf("%d\t",a[i]);
return 0;
}

