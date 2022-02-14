//N-Queen Program
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
#include<stdlib.h>
int x[10],n;
void nqueen(int k);
int place(int k,int i);
//main function
main()
{
	int i;
	printf("\nEnter the number of queens:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  x[i]=0;
	nqueen(1);//calling of function
}
//n-queens function
void nqueen(int k)
{
	int i,j;
	static int ns;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))//check kth queen can be placed in ith column
		{
			x[k]=i;
			if(k==n)
			{
				ns++;
				printf("\nThe solution-%d:\n",ns);
				for(j=1;j<=n;j++)
				printf("x[%d]=%d\t",i,x[j]);
			}
			else
			nqueen(k+1);
		}
	}
}
//place function
int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]==i||(abs(k-j))==abs(i-x[j]))
		return 0;
	}
	return 1;
}

