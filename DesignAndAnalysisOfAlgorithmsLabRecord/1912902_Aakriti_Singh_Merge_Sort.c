//Merge Sort Program
// Made by Aakriti Singh 
//Roll No-1912902

#include<stdio.h>
int b[20];
// Merge function
void merge(int a[20],int low,int mid,int high)
{
int i,j,h,k;
i=low; h=low; j=mid+1;
while(h<=mid && j<=high)
{
if(a[h] < a[j])
 { b[i]=a[h]; h=h+1;
 }
else
 {  b[i]=a[j];  j=j+1;
 }
i=i+1;
}
   if(h>mid) for(k=j;k<=high;k++)
                  {  b[i]=a[k];  i++;
                  }
   if(j>high) for(k=h;k<=mid;k++)
                  {  b[i]=a[k];  i++;
                  }
for(k=low;k<=high;k++)  a[k]=b[k];    
}


// Merge Sort Function
void merge_sort(int a[20],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
merge(a,low,mid,high);
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
merge_sort(a,0,n-1);
printf("\n Sorted Array elements are\n");
for(i=0;i<n;i++) printf("%d\t",a[i]);
return 0;
}
