// program for Tower of Hanoi
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
int cnt=0;   // count the no. of disk movement
void TowerOfHanoi(int n,char TA, char TB, char TC)
{   
  if (n >= 1)
    {
    	TowerOfHanoi(n-1,TA, TC, TB);
    	printf("\n Move  disk-%d from Tower-%c to Tower-%c",n,TA,TB);
    	TowerOfHanoi(n-1,TC,TB,TA);
      cnt++;
   } 
}

int main()
{  int n;
   printf("\nEnter the numeber disk:");
   scanf("%d",&n);
   TowerOfHanoi(n,'A','B','C');
   printf("\n #disk movement=%d",cnt);
   return 0;
}
	

