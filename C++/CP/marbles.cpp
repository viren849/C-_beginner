#include<iostream>
using namespace std;
#include<string>
#include<limits.h>

//MARBLES CODECHEF
bool isvowel(char x)
{
  if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
    return 1;
  return 0;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
     string s,p;
     cin>>s>>p;
   
   int mn=INT_MAX; 
   
   for(char c='a';c<='z';c++)
   { 
    
    int op=0;
       for(int i=0;i<n;i++)
         {
           char si=s[i];
           char pi=p[i];
          if(si=='?') si=c;
          if(pi=='?') pi=c;
          if(si!=pi)
          {
               bool sx=isvowel(si);
               bool px=isvowel(pi);

               if(sx != px)
                op+=1;
              else
                op+=2;
          }
        }
      //cout<<s<<" "<<p<<endl;
     mn=min(op,mn);
     //cout<<mn<<endl;
   }
    cout<<mn<<endl; 
  }
  return 0;
}