#include<stdio.h>
#include<math.h>
int main()
{
  int np,nf,j;
  int hit=0,mis=0,pos=-1;
  
  
  scanf("%d",&np);
   int pages[np];
  for(int i=0;i<np;i++)
    scanf("%d",&pages[i]);

  scanf("%d",&nf);

int frames[nf];

  for(int i=0;i<nf;i++)
     frames[i]=-1;

  for(int i=0;i<np;i++)
  {
    for(j=0;j<nf;j++)
    {
      if(pages[i]==frames[j])
      {
        hit++;
        break;
      }
    }
    if(j==nf){
      mis++;
      pos=(pos+1)%nf;
      frames[pos]=pages[i];
    }
  }
  printf("%d\n",hit);
  printf("%d",mis);
  return 0;
}