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
  printf("%d\n",dir);
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
  int s=n+2;
  int queue[s];
  queue[0]=0;
  queue[s-1]=199;
  int ind=1;
  for(int i=1;i<=n;i++){
    queue[i]=arr[i-1];
    if(head>arr[i])
       ind++;
  }
  
  for(int i=0;i<n+2;i++)
    printf("%d ",queue[i]);
  int sum =0;
    printf("\n");

    if(dir==1)
    {
      for(int i=ind+1;i<s;i++)
      {
        printf("%d ",queue[i]);
        sum+=(abs(queue[i]-head));
        head=queue[i];
      }
      for(int i=0;i<=ind;i++)
      {
         printf("%d ",queue[i]);

        sum+=(abs(queue[i]-head));
        head=queue[i];
      }
    }
    else
    {
      for(int i=ind;i>=0;i--)
      {
        sum+=(abs(queue[i]-head));
        head=queue[i];
      }
      for(int i=s-1;i>ind;i--)
        {
        sum+=(abs(queue[i]-head));
        head=queue[i];
      }
    }
    printf("\n%d",sum );
  return 0;
}