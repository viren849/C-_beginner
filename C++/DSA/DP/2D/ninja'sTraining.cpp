//NINJA'S Training....

#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
using namespace std;
int dp[100][100];
int training(vector<vector<int>>&arr,int n,int last)
{
	if(n==0)
		{
			int maxi=0;
			for(int i=0;i<3;i++)
				if(i!=last)
				  maxi=max(maxi,arr[0][i]);
			return maxi;
		}

	int maxi=INT_MIN;
	int sum=0;

	for(int i=0;i<3;i++)
	{
		if(i!=last)
			sum=arr[n][i]+training(arr,n-1,i);
		maxi=max(sum,maxi);
	}
	
   return maxi;
}
int memotraining(vector<vector<int>>&arr,int n,int last)
{
	if(n==0)
		{
			int maxi=0;
			for(int i=0;i<3;i++)
				if(i!=last)
				maxi=max(maxi,arr[0][i]);
			return maxi;
		}
	if(dp[n][last]!=-1)return dp[n][last];
	int maxi=INT_MIN;
	int sum=0;
	for(int i=0;i<3;i++)
	{
		if(i!=last)
			sum=arr[n][i]+memotraining(arr,n-1,i);
		maxi=max(sum,maxi);
	}
   return dp[n][last]=maxi;
}
int tabulation(vector<vector<int>>&arr,int n,int l)
{
    dp[0][0]=max(arr[0][1],arr[0][2]);
    dp[0][1]=max(arr[0][2],arr[0][0]);
    dp[0][2]=max(arr[0][0],arr[0][1]);
    dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int i=1;i<n;i++)
    {
    for(int last=0;last<4;last++)
        {
            int sum=0;
            for(int j=0;j<3;j++)
            {
                if(j!=last)
                    sum=arr[i][j]+dp[i-1][j];
                dp[i][last]=max(sum,dp[i][last]);
            }

        }
    }
    return dp[n-1][3];
}
int spaceopti(vector<vector<int>>&arr,int n,int l)
{
    vector<int>prev(4,0);
    prev[0]=max(arr[0][1],arr[0][2]);
    prev[1]=max(arr[0][2],arr[0][0]);
    prev[2]=max(arr[0][0],arr[0][1]);
    prev[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int i=1;i<n;i++)
    {
        vector<int>cur(4,0);
    for(int last=0;last<4;last++)
        {
            
            int sum=0;
            for(int j=0;j<3;j++)
            {
                if(j!=last)
                    sum=arr[i][j]+prev[j];
                cur[last]=max(sum,cur[last]);
            }

        }
        prev=cur;
    }
    return prev[3];

}
int main()
{
    int n;
    cin>>n;
    //memset(dp,-1,sizeof(dp));
    vector<vector<int>>arr(n,vector<int>(3,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    cout<<spaceopti(arr,n,3);
}
