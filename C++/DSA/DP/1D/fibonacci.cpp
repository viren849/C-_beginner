//Fibonacci number...
#include<iostream>
#include<cstring>
using namespace std;
int dp[50];
int fib(int n)
{
   if(n<=1)return n;
   return fib(n-1)+fib(n-2);
}
int memfib(int n)
{
   if(n<=1)return n;
   if(dp[n]!=-1)return dp[n];
   return dp[n]=fib(n-1)+fib(n-2);
}
int bottomup(int n)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
      dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int spaceoptimis(int n)
{
  int a=0,b=1;
  int ans;
  for(int i=2;i<=n;i++)
  {
    ans=a+b;
    a=b;
    b=ans;
  }
  return ans;
}
int main()
{
  int n;
  memset(dp,-1,sizeof(dp));
  cin>>n;
 cout<<spaceoptimis(n);
}