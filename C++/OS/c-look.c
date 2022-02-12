#include<stdio.h>
#include<math.h>
int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];

  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  
  int head,dir;
  scanf("%d",&head);
  scanf("%d",&dir);
  
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
      if(arr[j]>arr[j+1])
      {
        int tmp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=tmp;
      }
  }
  
  int queue[n];
  int ind=0;
  for(int i=0;i<n;i++){
    queue[i]=arr[i];
    if(head>arr[i])
       ind++;
  }
  
  for(int i=0;i<n;i++)
    printf("%d ",queue[i]);
  int sum =0;
    printf("\n");
   
   if(dir==1)
   {
    for(int i=ind;i<n;i++)
    {
      sum+=(abs(head-queue[i]));
       head=queue[i];
    }
    for(int i=0;i<ind;i++)
     {
      sum+=(abs(head-queue[i]));
       head=queue[i];
    } 
   }
   else
   {
    for(int i=ind-1;i>=0;i--)
    {
      sum+=(abs(head-queue[i]));
       head=queue[i];
    }
    for(int i=n-1;i>=ind;i--)
    {
      sum+=(abs(head-queue[i]));
       head=queue[i];
    }
   }
  printf("\n%d",sum);
  return 0;
}