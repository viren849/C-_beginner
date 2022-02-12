#include<iostream>

using namespace std;

int stair(int n)
{
  if(n==0)
    return 1;
  if(n==1)return 1;
  int l=0,r=0;
   l+=stair(n-1);//either one step 
   r+=stair(n-2);// or two step..
  return l+r;
}
int main()
{

  int n;
  cin>>n;

  int res=stair(n);
  cout<<res;
  
}