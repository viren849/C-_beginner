//subset sum......
#include<iostream>
#include<vector>
using namespace std;

void recursion(vector<int>&ans,int arr[],int n,int sum)
{
	  if(n<0)
	  {
	  	ans.push_back(sum);
        return ;
	  }
	  recursion(ans,arr,n-1,sum+arr[n]);
	  
	  recursion(ans,arr,n-1,sum);
}
void recursion1(vector<int>&ans,int arr[],int n,int sum)
{
	  if(n<0)
	  {
	  	ans.push_back(sum);
        return ;
	  }
	  sum+=arr[n];
	  recursion1(ans,arr,n-1,sum);
	  sum-=arr[n];
	  recursion1(ans,arr,n-1,sum);
}

void recursion2(vector<int>&ans,int arr[],int n,int sum)
{
	  ans.push_back(sum);

	  for(int i=n;i>=0;i--)
	  {
	  	recursion2(ans,arr,i-1,sum+arr[i]);
	  }
}
int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int>ans;
    
    recursion2(ans,arr,n-1,0);
	for(int s: ans)
		cout<<s<<" ";
}