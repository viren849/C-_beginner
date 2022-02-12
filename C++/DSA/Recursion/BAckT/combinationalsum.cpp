
//Combinational sum
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


// candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

class Solution {
public:
static void recursion(vector<vector<int>>&ans,vector<int>&num,vector<int>&tmp,int k,int i)
    {
      if(k<0)
          return ;
      if(k==0)
      {
          ans.push_back(tmp);
          return;
      }
        if(i >= num.size())
        {  
            return;
        }
    tmp.push_back(num[i]);
    recursion(ans,num,tmp,k-num[i],i);
    tmp.pop_back();
    recursion(ans,num,tmp,k,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& num, int k) {
        vector<int>tmp;
        vector<vector<int>>ans;
        recursion(ans,num,tmp,k,0);
        return ans;
    }
};

//COMBINATIONAL SUM II

class Solution {
public:
    
    void recursion(vector<vector<int>>&ans,vector<int>&num,vector<int>tmp,int index,int k)
    {    
        if(k==0)
          ans.push_back(tmp);
        if(k<0) return;
        for(int i=index;i<num.size();i++)
        {
            if(i>index && num[i] == num[i-1]) continue;
             tmp.push_back(num[i]);
            recursion(ans,num,tmp,i+1,k-num[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& num, int k) {
        vector<vector<int>>ans;
        vector<int>tmp;
        sort(num.begin(),num.end());
        recursion(ans,num,tmp,0,k);
        return ans;
    }
};

//CombinationalsumIII 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
       
    static void recursion(int arr[],vector<vector<int>>&ans,vector<int>tmp,int k ,int index,int sum)
    {
        if(sum == 0 and k==0)
            ans.push_back(tmp);
        if(sum<0 and k<0)return;
        
        for(int i=index;i<9;i++)
        {
            if(k>0)
            {
                tmp.push_back(arr[i]);
                recursion(arr,ans,tmp,k-1,i+1,sum-arr[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;
        vector<int>tmp;
         int arr[]={1,2,3,4,5,6,7,8,9};
        recursion(arr,ans,tmp,k,0,n);
        return ans;
    }
};