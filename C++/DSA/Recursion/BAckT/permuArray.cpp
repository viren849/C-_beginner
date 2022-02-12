//permutation.....
#include<iostream>
#include<vector>
using namespace std;

void recursion(vector<vector<int>>&ans,vector<int>&arr,int index,vector<int>tmp)
{    

	 if(index==arr.size()){
	  ans.push_back(arr);
	  return;
	}

	  for(int i=index;i<arr.size();i++)
	  {
	  	  
	  	  swap(arr[i],arr[index]);
	  	  recursion(ans,arr,index+1,tmp);
	  	  swap(arr[i],arr[index]);
	  	
	  }
}

void recursion2(vector<vector<int>>&ans,vector<int>&arr,vector<bool>&used,vector<int>tmp)
{    

	 if(tmp.size()==arr.size()){
	  ans.push_back(tmp);
	  return;
	}

	  for(int i=0;i<arr.size();i++)
	  {
	  	if(used[i]==0)
	  	{   
	  		used[i]=1;
	  	  tmp.push_back(arr[i]);
	  	  recursion2(ans,arr,used,tmp);
	  	  used[i]=0;
	  	  tmp.pop_back();
	  	}
	  }
}
void recursion3(vector<vector<int>>&ans,vector<int>&arr,vector<bool>&used,vector<int>tmp)
{    

	 if(tmp.size()==arr.size()){
	  ans.push_back(tmp);
	  return;
	}

	  for(int i=0;i<arr.size();i++)
	  {
	  	if (used[i]||i>0 && arr[i]==arr[i-1] && !used[i-1])continue;
	  	 
	  	  used[i]=1;
	  	  tmp.push_back(arr[i]);
	  	  recursion3(ans,arr,used,tmp);
	  	  used[i]=0;
	  	  tmp.pop_back();
	  	 
	  }
}
int main()
{
	int n;
	cin>>n;

	vector<int>arr(n);

	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<vector<int>>ans;
    vector<bool>used(n);
    recursion(ans,arr,0,{});
	for(auto s: ans)
	{
		for(int i: s)
		cout<<i<<" ";
	  cout<<endl;
	}
}
