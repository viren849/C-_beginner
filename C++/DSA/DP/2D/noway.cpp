#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//either to go right ,down....
int dp[1000][1000];
int matrix(int n,int m)
{
	if(n==0 && m==0)
		return 1;
	if(n<0 || m<0)
		return 0;
	int up=matrix(n-1,m);
	int lf=matrix(n,m-1);
	return up+lf;
}

int memomatrix(int n,int m)
{
	if(n==0 && m==0)
		return 1;
	if(n<0 || m<0)
		return 0;
	if(dp[n][m]!=-1)return dp[n][m];
	int up=memomatrix(n-1,m);
	int lf=memomatrix(n,m-1);
	return dp[n][m]=up+lf;
}
int tabulation(int n,int m)
{
	 
    //keep in mind for base cases...
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(i==0 && j==0)dp[i][j]=1;
		    else{
		    	int up=0,lf=0;
		    	if(i>0)up=dp[i-1][j];
		    	if(j>0)lf=dp[i][j-1];
		    	dp[i][j]=up+lf;
		       }
				
	return dp[n][m];
}
int spaceopti(int n,int m)
{
	vector<int>prev(m+1,0);
	prev[0]=1;
    
	for(int i=0;i<=n;i++)
		{
		  vector<int> cur(m+1,0);
		for(int j=0;j<=m;j++)
			if(i==0 && j==0)cur[j]=1;
		    else{
		    	int up=0,lf=0;
		    	if(i>0)up=prev[j];
		    	if(j>0)lf=cur[j-1];
		    	cur[j]=up+lf;
		       }
		       prev=cur;
		   }
	 return prev[m];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	cout<<spaceopti(n-1,m-1);
    return 0;
}