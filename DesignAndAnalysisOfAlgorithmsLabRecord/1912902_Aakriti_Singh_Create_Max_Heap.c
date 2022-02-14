//heapCreation
//maxheap
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
void maxheapify(int a[20],int i,int n);
void buildmaxheap(int a[20],int n);
int main()
{
	int n,i,a[20];
	printf("\nEnter the number of elements");
	scanf("%d",&n);
	printf("\nEnter the array elements for Creation of max heap");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	printf("\n Original array:\n");
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
	buildmaxheap(a,n);
	printf("\n Max heap is\n");
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
}

void buildmaxheap(int a[20],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	   maxheapify(a,i,n);
}

void maxheapify(int a[20],int i,int n)
{
	int l,r,large,temp;
	l=2*i;
	r=2*i+1;
	if(a[l]>a[i])
	  large=l;
     else 
	 large=i;
     
	if((r<=n) && (a[r] > a[large]))
	     large=r;
	if(large!=i)
	{
		temp=a[i];
		a[i]=a[large];
		a[large]=temp;
		maxheapify(a,large,n);
	}
}
