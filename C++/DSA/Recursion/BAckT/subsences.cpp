//print subsequences with sum k
//all kind of pattern...
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// printing all the subsequences .......
  void recursion(int arr[],int n,int k,vector<vector<int>>&ans,vector<int>&tmp)
  {
    if(n < 0)
      {  if(k==0)
       ans.push_back(tmp);
       return;
      }
    
    tmp.push_back(arr[n]);
    recursion(arr,n-1,k-arr[n],ans,tmp);
    tmp.pop_back();
    recursion(arr,n-1,k,ans,tmp);
  }

  // print any of the one subsequences.....

  bool recursion1(int arr[],int n,int k,vector<vector<int>>&ans,vector<int>&tmp)
  {
    if(n < 0)
      {  if(k==0){
             ans.push_back(tmp);
             return 1;
            }
         return 0;
      }
    
    tmp.push_back(arr[n]);
    
    if(recursion1(arr,n-1,k-arr[n],ans,tmp))
        return 1;
    tmp.pop_back();
     if(recursion1(arr,n-1,k,ans,tmp))
        return 1;
    return 0; 
  }

  //count the subsequences........
  int recursion2(int arr[],int n,int k,vector<vector<int>>&ans,vector<int>&tmp)
  {
    if(n < 0)
      {  if(k==0){
             return 1;
            }
         return 0;
      }
    
    tmp.push_back(arr[n]);
    
    int l= recursion2(arr,n-1,k-arr[n],ans,tmp);   
    tmp.pop_back();
     int r=recursion2(arr,n-1,k,ans,tmp);
        
    return l+r; 
  }
int main()
{
  int n;
  cin>>n;
  int arr[n];
  vector<int>tmp;
  vector<vector<int>>ans;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k;
  cin>>k;

  int x=recursion2(arr,n-1,k,ans,tmp);
  recursion(arr,n-1,k,ans,tmp);
   cout<<x<<endl;
  for(auto i:ans)
    {for(int j: i)
      cout<<j<<" ";
    cout<<endl;
  }
}