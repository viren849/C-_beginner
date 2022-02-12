#include<stdio.h>
#include<math.h>
//SCAN DISK SCHEDULING .........
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
  //0 for left......
  //1 for right......
  int dir;
  scanf("%d",&dir);
  for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++)
    {
         if(arr[j]>arr[j+1])
         {
          int temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
         }
    }

    int c=0;
    for(int i=0;i<n;i++)
      if(arr[i]<head) c++;
    
  int sum=0;
  
  int queue[n+1];
   int l=0;
   if(dir==0) 
    queue[0]=0;
  else queue[n]=199;

   
   
   if(dir==0){
    int l=1;
     for(int i=0;i<=n;i++)
        queue[l++]=arr[i]; 
    }
    else
        { 
          int r=0;
          c=c-1;
          for(int i=0;i<n;i++)
          queue[r++]=arr[i];
        }
    for(int i=0;i<=n;i++)
    printf("%d ",queue[i]);     
   
  int z=2;
    while(z--)
    {
      if(dir==0)
      {
        for(int i=c;i>=0;i--)
        {
          sum+=(abs(queue[i]-head));
          head=queue[i];
        }
        dir=1;
      }
      else
      {
        for(int i=c+1;i<=n;i++)
        {
          sum+=(abs(queue[i]-head));
          head=queue[i];
        }
        dir=0;
      }
    }
  printf("\n%d",sum);
  return 0;
}