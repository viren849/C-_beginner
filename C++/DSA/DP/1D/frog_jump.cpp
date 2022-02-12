//frog Jump question
//0->3
//10 20 30 10
#include<iostream>
#include<limits.h>
#include<cstring>
using namespace std;
int dp[100];
int stair(int arr[],int n)
{
  if(n==0)
    return 0;
 
  int r=INT_MAX;
  int  l=abs(arr[n]-arr[n-1])+stair(arr,n-1);
  if(n>1)
   r=abs(arr[n]-arr[n-2])+stair(arr,n-2);
  return min(l,r);
}
int memostair(int arr[],int n)
{
  if(n==0)
    return 0;

  if(dp[n]!=-1)return dp[n];

  int r=INT_MAX;

  int l=abs(arr[n]-arr[n-1])+stair(arr,n-1);
  if(n>1)
   r=abs(arr[n]-arr[n-2])+stair(arr,n-2);

  return dp[n]=min(l,r);
}
int tabulation(int arr[],int n)
    {
       dp[0]=0;
      // dp[1]=abs(arr[0]-arr[1]);

       int l, r=INT_MAX;
       for(int i=1;i<n;i++)
       {
         l=abs(arr[i]-arr[i-1])+dp[i-1];
         
         if(i>1)r=abs(arr[i]-arr[i-2])+dp[i-2];

         dp[i]=min(l,r);
       }
       return dp[n-1];
    }

int spaceopti(int arr[] ,int n)
{
    int a=0;
    int b=abs(arr[0]-arr[1]);
    int ans;

    for(int i=2;i<n;i++)
    {
          int l=abs(arr[i]-arr[i-1])+b;
          int r=abs(arr[i]-arr[i-2])+a;
          ans=min(l,r);
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
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int res=spaceopti(arr,n);
  cout<<res;
  
}