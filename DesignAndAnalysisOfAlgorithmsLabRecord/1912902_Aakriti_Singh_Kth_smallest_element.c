         //kth smallest element from array of n elements without sorting,where 1<=k<n
         //Made by-Aakriti Singh  Roll No.-1912902
#include<stdio.h>
void swap(int *a, int *b)
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
int CreatePartition(int as[], int l, int h) {
   int pi, in, i;
   in = l;
   pi = h;
   for(i=l; i < h; i++) {
      if(as[i] < as[pi]) {
         swap(&as[i], &as[in]);
         in++;
      }
   }
   swap(&as[pi], &as[in]);
   return in;
}
int Partition(int as[], int low, int high, int k) {
   int p_in;
   if(low < high) {
      p_in = CreatePartition(as, low, high);
      if(p_in == k-1)
         return k-1;
      else if(p_in > k-1)
         Partition(as, low, p_in-1, k);
      else
         Partition(as, p_in+1, high, k);
   }
}
int main() {
   int n, i, k, k_k;
   printf("\nEnter the number of array elements: ");
   scanf("%d", &n);
   int as[n];
    printf("Enter element : ");
   for(i = 0; i < n; i++) {
      scanf("%d", &as[i]);
   }
   printf("\nEnter the k for the kth smallest element: ");
   scanf("%d", &k);
   k_k = Partition(as, 0, n-1, k);
   printf("\nThe kth smallest element: %d",as[k_k]);
   return 0;
}
