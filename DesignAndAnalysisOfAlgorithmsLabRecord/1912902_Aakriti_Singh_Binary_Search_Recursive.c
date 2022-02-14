//Binary Search Recursive Program
// Made by-Aakriti Singh
//Roll No.-1912902

#include<stdio.h>
//Binary search function
int Binsearch(int a[20], int low, int high, int x)
{
int mid;
if(low==high)
{ if(x==a[low]) return low;
else return 0;
}
else { mid=(low+high)/2;
  if(x==a[mid]) return mid;
  else if(x<a[mid])
     Binsearch(a,low,mid-1,x);
  else  Binsearch(a,mid+1,high,x);
}
}

//Main function
int main()
{
int a[20],n,i,x,pos;
printf("\nEnter the size of array:");
scanf("%d",&n);
printf("\nEnter the %d elements in ascending order\n",n);
for(i=1;i<=n;i++) scanf("%d",&a[i]);
printf("\nEnter element to search:"); scanf("%d",&x);
pos=Binsearch(a,1,n,x);
if(pos!=0) printf("\nElement present at position=%d",pos);
else printf("\nElement is not present\n");
return 0;
}

