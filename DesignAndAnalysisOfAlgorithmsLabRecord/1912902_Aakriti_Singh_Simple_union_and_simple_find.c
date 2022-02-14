//SIMPLE UNION AND SIMPLE FIND
//Made By-Aakriti Singh
//Roll No.-1912902

#include<stdio.h>
int n,p[20];
//Simple union function
void setunion(int i,int j)
{
	//i and j are the roots of tree that represents the sets
	p[i]=j;
}
//simple find function
int sfind(int i)
{
	//it return the root of tree that contain element i
	int j;
	j=i;
	while(p[j]>0)
	  j=p[j];
	return j;
}
int main()
{
	int i,j,r1,r2,ch;
	printf("\n Enter the value of n:");
	scanf("%d",&n);
	//set each element in their own set p[i]=-1
	for(i=1;i<=n;i++)
	p[i]=-1;
	
	printf("\n P[]");
	for(i=1;i<=n;i++) printf("%d\t",p[i]);
	printf("\n ele[]=");
	for(i=1;i<=n;i++)
	  printf("%d\t",i);
	//menu driven choice based
	do{
	printf("\n 1.Simple union 2.Simple find 3.Exit\n");
	printf("\nEnter the choice:"); scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\n Enter the root of two tree of the sets\n");
		       scanf("%d%d",&r1,&r2);
		       if((p[r1]==-1) && (p[r2]==-1))
		         setunion(r1,r2);
		       else printf("Invalid roots"); break;
		case 2:printf("\n Enter the element to find:");
		       scanf("%d",&r1);
		       r2=sfind(r1);
		       printf("\n The element %d is in the set whose root is=%d\n",i,j);
		       break;
		case 3:printf("\n Thank You"); break;
	}
	printf("\n P[]=");
	for(i=1;i<=n;i++) printf("%d\t",p[i]);
	printf("\n ele[]=");
	for(i=1;i<=n;i++) printf("%d\t",i);
}while(ch>=1 && ch<=2);
return 0;
}
