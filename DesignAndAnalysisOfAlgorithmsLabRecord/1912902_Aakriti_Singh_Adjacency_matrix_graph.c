#include<stdio.h>
//Adjacency MATRIX REPRESENTATION OF GRAPH
void printmatrix(int a[10][10],int r,int c)
{
int i,j;
printf("\n Adjacency matrix size %d*%d is \n",r,c);
for(i=1;i<=r;i++)
{
   for(j=1;j<=c;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
}
int main()
{
int r,c,nv,ne,mat[10][10],v1,v2,i,j;
printf("\n Enter the no. of vertices and edge in the graph:");
scanf("%d%d",&nv,&ne);
for(i=1;i<=nv;i++)
for(j=1;j<=nv;j++)
mat[i][j]=0;

for(i=1;i<=ne;i++)
{
printf("\n Enter the two end vertices of edge no. %d\n",i);
scanf("%d%d",&v1,&v2);
mat[v1][v2]=1;
mat[v2][v1]=1;
}

printmatrix(mat,nv,nv);
}