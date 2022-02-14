#include<stdio.h>
#include<stdlib.h>
int p[10];
void weightedunion(int i,int j)
{
//i and j are the roots of tree of different sets
int temp;
if((p[i]>0)||(p[j]>0))
 printf("\n invalid roots\n");
 else
 {
  temp=p[i]+p[j];
  if(p[i]>p[j])
  {
  p[i]=j; p[j]=temp;
   }
   else
       p[j]=i; p[i]=temp;
 }
}
//collapsing find algorithm or path compression algorithm
int collapsingfind(int i)
{
int r,s;
r=i;
while(p[r]>0)
 r=p[r];
while(i!=r)
{
s=p[i]; p[i]=r;
i=s;
}
return r;
}
int main()
{
int i,j,r1,r2,ch,n;
printf("\n Enter the value of n:");
scanf("%d",&n);
//initially there is forest of trees with single node
for(i=1;i<=n;i++)
p[i]=-1;
printf("\n   P[]=");
for(i=1;i<=n;i++) printf("%d\t",p[i]);
printf("\n ele[]= ");
for(i=1;i<=n;i++) printf("%d\t",i);
do{
printf("\n1.Weighted Union 2.Collapsing find 3.exit\n");
printf("\nEnter the choice:"); scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n Enter the roots of the two sets\n");
      scanf("%d%d",&r1,&r2);
      if((p[r1]>0)||(p[r2]>0))
      printf("\nInvalid roots");
      else
      weightedunion(r1,r2);break;
   case 2:printf("\n Enter the element to find:");
          scanf("%d",&i);
          j=collapsingfind(i);
          printf("\nThe element %d in the set tree whose root is =%d\n",i,j);
          break;
            case 3:printf("Thankyou"); exit(0);
}
printf("\n   P[]=");
for(i=1;i<=n;i++) printf("%d\t",p[i]);
printf("\n ele[]= ");
for(i=1;i<=n;i++) printf("%d\t",i);
}while(ch>=1 && ch<=2);
}
