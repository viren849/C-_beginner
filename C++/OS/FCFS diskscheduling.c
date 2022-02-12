#include<stdio.h>
#include<math.h>
//FCFS disk scheduling ......algorithm...
int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int head;
  scanf("%d",&head);
  int sum=0;
  for(int i=0;i<n;i++)
  {
     sum+=(abs(head-arr[i]));
     head=arr[i];
  }
  printf("%d",sum);
  return 0;
}