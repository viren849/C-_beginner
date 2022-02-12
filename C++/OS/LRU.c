#include<stdio.h>
#include<math.h>
int main()
{
  int np,nf,j,f,k,l;
  int hit=0,mis=0,pos=-1;
  
  
  scanf("%d",&np);
   int pages[np];
  for(int i=0;i<np;i++)
    scanf("%d",&pages[i]);

  scanf("%d",&nf);

int frames[nf];

  for(int i=0;i<nf;i++)
     frames[i]=-1;

  
   //LRU CACHE
   for(int i=0;i<np;i++)
   {
    for( j=0;j<nf;j++)
    {
         if(pages[i]==frames[j])
         {
          hit++;
          for(k=0;k<i;k++)
            if(pages[k]==frames[j])
            {
              pages[k]=-1;
              break;
            }
            break;
         }
    }
    if(j==nf)
    {
      f=0;
      mis++;
      for(j=0;j<nf;j++)
        if(frames[j]==-1)
        {
          frames[j]=pages[i];
          f=1;
          break;
        }
        if(f==0)
        {
          for(k=0;k<i;k++)
            if(pages[k]!=-1){
              for(l=0;l<nf;l++)
                if(pages[k]==frames[l])
                {
                  pages[k]=-1;
                  frames[l]=pages[i];
                  break;
                }
                break;
            }
        }
    }
   }
  printf("%d\n",hit);
  printf("%d",mis);
  return 0;
}