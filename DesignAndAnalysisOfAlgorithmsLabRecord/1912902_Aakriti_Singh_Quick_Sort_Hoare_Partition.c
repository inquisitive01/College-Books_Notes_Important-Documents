// Quick Sort Program using hoare partition last element as pivot
// Made by-Aakriti Singh
//Roll no-1912902

#include<stdio.h>
// Partitioning using Hoare Partition function as last element as pivot
int Hoare_Partition(int a[20], int p, int r)
{
int x,i,j,temp;
x=a[r];  i=p-1;  j=r+1;
while(1)
{
do
{ j=j-1;    
}while(a[j]>x);
do
{ i=i+1;
}while(a[i]<x);
if(i>=j)
return i;
temp=a[i];  a[i]=a[j];  a[j]=temp;  
}
}

// Quicksort function
void Quicksort(int a[20], int p, int r)
{ int q;
  if(p<r)
  {
  q=Hoare_Partition(a,p,r);
  Quicksort(a,p,q-1);
  Quicksort(a,q,r);
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

