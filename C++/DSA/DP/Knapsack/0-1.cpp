#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

/*
int knapsack(int n,int weight[],int values[],int W)
{
      if(n==0 || W==0)
        return 0;

      if(weight[n-1]<=W)
       {
        //backtracking...
          // W-=weight[n-1];
          // int x=values[n-1]+knapsack(n-1,weight,values,W);
          // W+=weight[n-1];

        int x=values[n-1]+knapsack(n-1,weight,values,W-weight[n-1]);//not backtracking

        int y=knapsack(n-1,weight,values,W);
        return max(x,y);
      }
          
      else 
        return knapsack(n-1,weight,values,W);
}
*/

//MEMOIZATION>>>>>>

int dp[100][100];//n,W
/*
int knapsack(int n,int weight[],int values[],int W)
{
      if(n==0 || W==0)
        return 0;
      
      if(dp[n][W]!=-1)
        return dp[n][W];

      if(weight[n-1]<=W)
       {
        //backtracking...
          // W-=weight[n-1];
          // int x=values[n-1]+knapsack(n-1,weight,values,W);
          // W+=weight[n-1];

        int x=values[n-1]+knapsack(n-1,weight,values,W-weight[n-1]);//not backtracking

        int y=knapsack(n-1,weight,values,W);
        return dp[n][W]= max(x,y);
      }
          
      else 
        return dp[n][W]= knapsack(n-1,weight,values,W);
}
*/
//TABULATION()

int knapsack(int n,int weight[],int values[],int W)
{
       for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        {
          if(i==0||j==0)
            dp[i][j]=0;
         else if(weight[i-1]>j)
            dp[i][j]=dp[i-1][j];
          else
            dp[i][j]=max(values[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
        }
        return dp[n][W];
}
int main()
{
  int n;
  cin>>n;
 // memset(dp,-1,sizeof(dp));
  int values[n];
  int weight[n];
  int W;

  for(int i=0;i<n;i++)
    cin>>values[i];
  for(int i=0;i<n;i++)
    cin>>weight[i];

  cin>>W;

  cout<<knapsack(n,weight,values,W);
  return 0;
}