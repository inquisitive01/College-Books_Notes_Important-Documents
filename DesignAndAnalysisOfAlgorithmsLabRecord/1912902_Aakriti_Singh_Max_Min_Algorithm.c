//Max Min Program
// Made by-Aakriti Singh
//Roll No.-1912902

#include<stdio.h>
//MaxMin function
void maxmin(int a[20],int low,int high,int *max,int *min)
{
int max1,min1,mid;
if(low==high)
{ *max=*min=a[low]; }
else if(low == (high-1))
{
if(a[low] > a[high]) { *max=a[low];  *min=a[high]; }
else {  *max=a[high]; *min=a[low]; }
}
else
{
mid=(low+high)/2;
maxmin(a,low,mid,max,min);
maxmin(a,mid+1,high,&max1,&min1);
if(min1 < *min) *min=min1;
if(max1 > *max) *max=max1;
}
}

//Main function
int main()
{
int a[20],n,i,max,min,low,high;
printf("\nEnter the size of array:"); scanf("%d",&n);
printf("\nEnter the %d elements:",n);
for(i=1;i<=n;i++) scanf("%d",&a[i]);
low=1; high=n;
maxmin(a,low,high,&max,&min);
printf("\nMax=%d\tand\tMin=%d",max,min);
return 0;
}

