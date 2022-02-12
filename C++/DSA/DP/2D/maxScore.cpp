#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int dp[1000][1000];
int func(int arr[],int mul[],int s,int e,int m,int i)
  {
     if(m==i)
        return 0;
      int st= arr[s]*mul[i]+func(arr,mul,s+1,e,m,i+1);
      int en= arr[e]*mul[i]+func(arr,mul,s,e-1,m,i+1);
      return max(st,en);
  }
//here we don't need three variable we can use two 
// i and start and for the end=n-1-(i-start);
  int func2(int arr[],int mul[],int s,int n,int m,int i)
  {
    if(m==i)
        return 0;
     
      int st= arr[s]*mul[i]+func2(arr,mul,s+1,n,m,i+1);

       int e=n-1-(i-s);
      int en= arr[e]*mul[i]+func2(arr,mul,s,n,m,i+1);

      return max(st,en);
  }
  int memofunc2(int arr[],int mul[],int s,int n,int m,int i)
  {
    if(m==i)
        return 0;
     if(dp[i][s]!=-1)
      return dp[i][s];
      int st= arr[s]*mul[i]+memofunc2(arr,mul,s+1,n,m,i+1);

       int e=n-1-(i-s);
      int en= arr[e]*mul[i]+memofunc2(arr,mul,s,n,m,i+1);

      return dp[i][s]=max(st,en);
  }

  int tabulation(int arr[],int mul[],int s,int n,int m,int i)
  {
    //as global dp will bw zero so no need for base case in this
    for(int i=m-1;i>=0;i--)
    {
       for(int s=i;s>=0;s--)
       {
        
          int st=arr[s]*mul[i]+dp[i+1][s+1];
         int e=n-1-(i-s);
         int en=arr[e]*mul[i]+dp[i+1][s];
         dp[i][s]=max(st,en);
        
       }
    }
    return dp[0][0];
  }

int main()
{
   int n,m;
   cin>>n>>m;
   int arr[n];
   int mul[m];
   for(int i=0;i<n;i++)
     cin>>arr[i];
   for(int i=0;i<m;i++)
     cin>>mul[i];
   cout<<tabulation(arr,mul,0,n,m,0);
}