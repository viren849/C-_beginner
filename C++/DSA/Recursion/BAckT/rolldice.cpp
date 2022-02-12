//Dice roll 
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
 
 int m=1e9+7;
 int dp[32][1002];
 int recur1(int n,int k,int tar)
 {
      if(tar == 0 && n==0)return 1;

      if(n<=0 || tar<0)return 0;
      
      if(dp[n][tar]!=-1)return dp[n][tar];

      int res=0;

      for(int i=1;i<=k;i++)
      {
       res= (res%m  + recur1(n-1,k,tar-i)%m)%m;
      }
      dp[n][tar]=res;
      return dp[n][tar];

 }
 

 int recur(int n,int k,int tar)
 {
      if(tar == 0 && n==0)return 1;

      if(n<=0 || tar<0)return 0;

      int res=0;
      for(int i=1;i<=k;i++)
      {
       res+=recur(n-1,k,tar-i);
      }
      return res;
 }
 
 int main()
 {
    int n,k,tar;
    cin>>n>>k>>tar;

    
    memset(dp,-1,sizeof(dp));
   
    cout<<recur2(n,k,tar);
    return 0;
 }