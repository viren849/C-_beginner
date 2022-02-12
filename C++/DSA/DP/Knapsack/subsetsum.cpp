//subset sum problem
// output true or false......

#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
using namespace std;
int dp[50][50];
int subsetsum(int arr[],int n,int S)
{
	if(S==0)return 1;
	if(n==0 || S<0)return 0;
	if(arr[n-1]<=S)
		if(subsetsum(arr,n-1,S-arr[n-1]))return 1;
	if(subsetsum(arr,n-1,S))return 1;
	return 0;
}
bool subsetsum2(int arr[],int n,int S)
{
	if(S==0)return 1;
	if(n==0||S<0)return 0;
	bool t=0,r;
	if(arr[n-1]<=S)
	  t=subsetsum2(arr,n-1,S-arr[n-1]);
	r=subsetsum2(arr,n-1,S);
	return t|r;
}
bool subsetsum2(int arr[],int n,int S)
{
	if(S==0)return 1;
	if(n==0)return arr[0]==S;   //tabu--> dp[i][arr[0]]=1 ..//baki false hoga
	bool t=0,r;
	if(arr[n]<=S)
	  t=subsetsum2(arr,n-1,S-arr[n]);
	r=subsetsum2(arr,n-1,S);
	return t|r;
}

int memosubsetsum(int arr[],int n,int S)
{
    if(dp[n][S]!=-1)return dp[n][S];
	if(S==0)return 1;
	
	if(n==0 || S<0)return 0;
	
	if(arr[n-1]<=S)
		if(memosubsetsum(arr,n-1,S-arr[n-1]))return dp[n][S]=1;
	if(memosubsetsum(arr,n-1,S))return dp[n][S]=1;
	return dp[n][S]=0;
}
int Tabulation(int arr[],int n,int S)
{
	//i=n,j=S;
	for(int i=0;i<=S;i++)
		dp[0][i]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=S;j++)
		    {
                if(arr[i-1]<=j) 
                	dp[i][j]=dp[i-1][j-arr[i-1]] | dp[i-1][j];
                else 
                	dp[i][j]=dp[i-1][j];
		    }
	    }
		return dp[n][S];
}

int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int arr[n];
	int S;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cin>>S;
    
   cout<<Tabulation(arr,n,S);
}