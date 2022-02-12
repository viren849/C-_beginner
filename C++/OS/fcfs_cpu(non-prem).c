#include<stdio.h>
#include<math.h>

int main()
{
  int p;
  scanf("%d",&p);

  int AT[p],BT[p],ST[p],EN[p];

  for(int i=0;i<p;i++)
    scanf("%d",&AT[i]);
  for(int i=0;i<p;i++)
    scanf("%d",&BT[i]);

ST[0]=AT[0];
EN[0]=BT[0];
  for(int i=1;i<p;i++)
  {
     if(AT[i]<EN[i-1])
       ST[i]=EN[i-1];
     else
      ST[i]=AT[i];

      EN[i]=ST[i]+BT[i];  
  }
  for(int i=0;i<p;i++){
    printf("%d ",ST[i]);
    printf("%d",EN[i]);
    printf("\n");
  }
  return 0;
}