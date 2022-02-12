//Longest Increasing Subsequence....

#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;

//at any index n ,i will check all the behind element if is small or not
//if small then it is the part of the subsequence (but not longest)
//then that small element --> n ka lis = lis(small)+1;

int dp[50];

int lis(int n,int arr[])
{
       int ans=1;
       for(int i=0;i<n;i++)
          if(arr[i]<arr[n])
              ans=max(ans,lis(i,arr)+1);
      return ans;
}

int memolis(int n,int arr[])
  {
    if(dp[n]!=-1)
      return dp[n];
     int ans=1;
    for(int i=0;i<n;i++)
          if(arr[i]<arr[n])
              ans=max(ans,memolis(i,arr)+1);
      return dp[n]=ans;
  }

  int Tabulation(int n,int arr[])
  {
    int maxi=INT_MIN;
     for(int j=0;j<n;j++)
     {
          int ans=1;
           for(int i=0;i<j;i++)
              if(arr[i]<arr[j])
                 ans=max(ans,dp[i]+1);
         dp[j]=ans;
     }

     for(int i=0;i<n;i++)
         maxi=max(dp[i],maxi);
     return maxi;
  }

//Binary Search......if we apply then we can get in nlogn ..
  

int main()
{
   int n;
   cin >> n;
   int arr[n];

   // memset(dp,-1,sizeof(dp));

   for(int i=0;i<n;i++)
      cin >> arr[i];

   int ans=INT_MIN;

   // for(int i=n-1;i>=0;i--)
   //   ans=max(ans,memolis(i,arr));

   cout<<Tabulation(n,arr);
}