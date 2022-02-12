//
//1004. Max Consecutive Ones III

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 


class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        int l=0,r=0,n=arr.size();
        int ans=0,z=0;
        while(r<n)
        {
           if(arr[r]==0)k--;
            
            if(k<0 and arr[l++]==0)k++;
            
            int len=r-l+1;
            ans=max(len,ans);
           r++; 
        }
        return ans;
    }
};