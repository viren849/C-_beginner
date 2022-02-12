class Solution {
public:
  
    int helper(vector<int>& nums, int x,int i,int n)
  {
    
        if(x==0)return 0;
        
     int l=1e6,r=1e6;
        
        
        if(i+1<n)
     l=1+helper(nums,x-nums[i],i+1,n);
        
        if(n-1>i)
     r=1+helper(nums,x-nums[n],i,n-1);
      
        
       return min(l,r);
  }

int minOperations(vector<int>& nums, int x) {
     // memset(dp,-1,sizeof(dp));
      int n=nums.size();
         int ans= helper(nums,x,0,n-1);
    return ans>1e6?-1:ans;
    }
};