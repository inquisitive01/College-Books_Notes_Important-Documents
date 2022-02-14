// program for selection sort
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
void selection(int a[20], int n)
{  int i, j,k, temp, cnt=0;

    for (i=0;i<n;i++)
      {
      	 j=i;
      	for(k=i+1; k<n; k++) 
      	  {  cnt++;
			if ( a[k] < a[j]) 
      	      j=k;
		  }
		  
		temp=a[i]; a[i]=a[j]; a[j]= temp;  
	  }
 printf("\n no. of elemets comparisons=%d",cnt);
}

int main()
{  int a[20], n, i;
   printf("\n Enter size of array elements:");
   scanf("%d",&n);
   printf("\n enter %d elements",n);
   for (i=0;i<n;i++)
    scanf("%d",&a[i]);
    
   printf("\n initial array elements: ");
   for(i=0;i<n;i++) printf("%d,  ",a[i]);
   // Sorting call of function
   selection(a,n);
   
   printf("\n sorted elements are:");
   for(i=0;i<n;i++) printf("%d,  ",a[i]); 
   
   return 0;
}
	

