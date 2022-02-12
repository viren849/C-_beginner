//min coin to get the value amount..
//coin change problem...
//INT_MAX-1 // INT_MIN+1....
#include<iostream>
#include<limits.h>
#include<cstring>
using namespace std;
int dp[10001][13];
int coin(int amt,int arr[],int n)
{
	if(amt == 0)return 0;

	if(n==0 || amt < 0)
      return INT_MAX-1;
   
   int l=INT_MAX,r;
    if(arr[n-1]<=amt)
    	l=1+coin(amt-arr[n-1],arr,n);
    r=coin(amt,arr,n-1);
   return min(l,r);
}

int memocoin(int amt,int arr[],int n)
{
	if(amt == 0)return 0;

	if(n==0 || amt < 0)
      return INT_MAX-1;

     if(dp[amt][n]!=-1)return dp[amt][n];

   int l=INT_MAX,r;
    if(arr[n-1]<=amt)
    	l=1+memocoin(amt-arr[n-1],arr,n);
    r=memocoin(amt,arr,n-1);
   return dp[amt][n]=min(l,r);
}
int Tabulation(int amt,int arr[],int n)
{
	
     for(int i=0;i<=amt;i++)
     {   
     	for(int j=0;j<=n;j++)
     	{
     		if(i==0)dp[i][j]=0;
     		else if(j==0)dp[i][j]=INT_MAX-1;
     		else
     		{
               int l=INT_MAX,r;
           if(arr[j-1]<=i)
    	      l=1+dp[i-arr[j-1]][j];
                r=dp[i][j-1];
             dp[i][j]=min(l,r); 
     		}
     		cout<<dp[i][j]<<" ";
     	}
     	cout<<endl;}

   return dp[amt][n];
}
int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int amt;
	cin>>amt;
	cout<<Tabulation(amt,arr,n);
}