//house robbery...
#include<iostream>
#include<limits.h>
#include<cstring>
using namespace std;
int dp[50];
int robber(int arr[],int n)
{
  if(n==0)
     return arr[0];
   if(n==1) 
    return max(arr[0],arr[1]);
  
   //there will be two condition either to rob or not 
  //if i don,t rob the house money arr[n-1] (last house one)
       int l=robber(arr,n-1);
  //if i rob the house money arr[n-2]+arr[n] (as two adjacent cant be robbed).
       int r=arr[n]+robber(arr,n-2);

      return max(l,r);

}
int memorobber(int arr[],int n)
{
  if(n==0)
     return arr[0];
   if(n==1) 
    return max(arr[0],arr[1]);
  if(dp[n] != -1)return dp[n];
   //there will be two condition either to rob or not 
  //if i don,t rob the house money arr[n-1] (last house one)
       int l=memorobber(arr,n-1);
  //if i rob the house money arr[n-2]+arr[n] (as two adjacent cant be robbed).
       int r=arr[n]+memorobber(arr,n-2);

      return dp[n]=max(l,r);

}
int tabulation(int arr[],int n)
{
     dp[0]=arr[0];
     dp[1]=max(arr[0],arr[1]);

     for(int i=2;i<n;i++)
       {
         dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
       }
       return dp[n-1];
}
int spaceopti(int arr[],int n)
{
   int a=arr[0];
   int b=max(arr[0],arr[1]);
   int ans;

   for(int i=2;i<n;i++)
   {
      ans=max(b,a+arr[i]);
      a=b;
      b=ans;
   }
   return b;
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