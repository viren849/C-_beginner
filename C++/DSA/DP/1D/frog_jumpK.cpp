//frog Jump question
//now jump upto k steps..
//10 20 30 10
#include<iostream>
#include<limits.h>
#include<cstring>
using namespace std;
int dp[100];
int stair(int arr[],int n,int k)
{
  if(n==0)
    return 0;
 
  int r,c=INT_MAX;

  for(int i=1;i<=k;i++)
    if(n-i>=0)
       {
           r=abs(arr[n]-arr[n-i])+stair(arr,n-i,k);
           c=min(r,c);
         }
   

  return c;
}
int memostair(int arr[],int n,int k)
{
  if(n==0)
    return 0;

  if(dp[n]!=-1)return dp[n];

  int r,c=INT_MAX;

  
  for(int i=1;i<=k;i++)
    if(n-i>=0)
        {
           r=abs(arr[n]-arr[n-i])+memostair(arr,n-i,k);
           c=min(r,c);
         }

  return dp[n]=c;
}
int tabulation(int arr[],int n,int k)
    {
      n++;
       dp[0]=0;
      // dp[1]=abs(arr[0]-arr[1]);

       int l,r;
       for(int i=1;i<n;i++)
       {
        r=INT_MAX;
          for(int j=1;j<=k;j++)
            if(i-j>=0)
            {
              l=abs(arr[i]-arr[i-j])+dp[i-j];
              r=min(r,l); 
            }
          dp[i]=r;
       }
       return dp[n-1];
    }

//it takes o(k) space but if( k==n ) then the space will become o(N).
int spaceopti(int arr[] ,int n,int k)
{
     int tmp[k];
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
  int k;
  cin>>k;
  int res=tabulation(arr,n-1,k);
  cout<<res;
  
}