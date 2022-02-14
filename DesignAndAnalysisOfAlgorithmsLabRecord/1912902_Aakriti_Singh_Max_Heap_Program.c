// Max heap Program
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
void max_heapify(int a[20], int i, int n)
{
	int l, r, large, temp;
	l=2*i;  r=2*i+1;
	if( l<=n &&  a[l]> a[i])
	   large=l;
	else large=i;
	if(r<=n && a[r]> a[large])
	   large=r;
	if(i!=large)
	   { temp=a[i]; a[i]= a[large]; a[large]=temp;
		  max_heapify(a, large,n);
	}
}
// Create Max-Heap
void create_maxheap(int a[20], int n)
{ 
   int i;
   for (i=n/2; i>=1; i--)
       max_heapify(a,i,n);
}

// Insert element in Max-Heap
void insertintomaxheap(int a[20],int n)
{
   int i, item;
   i=n;  item=a[n];
   while (i>1 && a[i/2]< item)
   { 
      a[i]=a[i/2];
      i=i/2;
   }
   a[i]=item;
	
}

 // Delete an element from Max-Heap
 int delmax(int a[20], int *n)
 {
 	int x=0;
 	if (*n==0) printf("\nheap is empty");
 	else
 	{ 
	  x=a[1];
	  a[1]=a[*n]; 
	  *n=*n-1;
 	  max_heapify(a,1,*n); 
 	}
 	return x;
 }




int main()
{  int n, i, a[20],item,ch;
   do
   {
   	printf("\n 1. create maxheap 2. insert element 3. delete element 4. Exit");
   	printf("\n Enter your choice:"); scanf("%d",&ch);
   	switch(ch)
   	 {
   	   case 1:  printf("\n enter the size of array:"); scanf("%d",&n);
   				printf("\n enter %d elements",n);
   				for(i=1;i<=n;i++)  scanf("%d",&a[i]);
   				printf("\n Array elements are\n");
  				 for(i=1;i<=n;i++)  printf("%d\t",a[i]);
   				create_maxheap(a,n);
  				 printf("\n Max heap elements are\n");
   				for(i=1;i<=n;i++)  printf("%d\t",a[i]); 
   				break;
   		case 2: printf("\n enter element to insert:");
  				scanf("%d",&item);
   				n=n+1;  a[n]=item;
   				insertintomaxheap(a,n);
				printf("\n Max heap after inserting elements %d are\n",item);
   				for(i=1;i<=n;i++)  printf("%d\t",a[i]); 
				break;
   		case 3: item=delmax(a,&n);
  				if(item != 0) 
   					printf("\n deleted element is =%d",item);
   				printf("\n Max heap after deletion\n ");
   				for(i=1;i<=n;i++)  printf("%d\t",a[i]);
   				break;
   		case 4: printf("\n Thank You");
		}
      }   while (ch>=1 && ch<=3);
   
   	return 0;
	}	
