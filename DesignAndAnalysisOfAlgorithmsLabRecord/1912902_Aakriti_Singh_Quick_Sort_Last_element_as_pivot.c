// Quick Sort Program with last element as pivot.
// Made by Aakriti Singh
//Roll No-1912902

#include<stdio.h>
// Partition function
int Partition(int a[20], int p, int r)
{ int i,j,x,temp;
x=a[r];  i=p-1;
for(j=p;j<=r-1;j++)
 if(a[j]<=x)
 {  i=i+1;
    if(i!=j)
    {
    temp=a[i];  a[i]=a[j];  a[j]=temp;
}
 }
a[r]=a[i+1];  a[i+1]=x;
return (i+1);
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

