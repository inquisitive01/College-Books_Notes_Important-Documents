// program for Bubble sort
//Made By-Aakriti Singh (Roll No.-1912902)

#include<stdio.h>
void bubble(int a[20], int n)
{  int i, j,k, temp, flag=1, cnt=0;

   for(i=1; (i<=n-1) && (flag==1 ); i++)
      { 
	       flag=0;
      	for(j=1; j<=n-i; j++) 
      	  {   cnt++;
			if ( a[j] > a[j+1]) 
      	     {
			   temp=a[j]; 
			   a[j]=a[j+1];
			   a[j+1]= temp;
			   flag=1;
		    }
		}

   }
   printf("\no. of elemets comparisons=%d",cnt);
}

int main()
{  int a[20], n, i;
   printf("\nEnter size of array elements:");
   scanf("%d",&n);
   
   printf("\n enter %d elements",n);
   for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
   printf("\n initial array elements: ");
   for(i=1;i<=n;i++) printf("%d,  ",a[i]);
   bubble(a,n);
   
   printf("\n sorted elements are:");
   for(i=1;i<=n;i++) printf("%d,  ",a[i]); 
   return 0;
}
	

	

