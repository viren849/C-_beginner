
//Min Cost Climbing Stairs
class Solution {
public:
    int func(vector<int>&dp,vector<int>&arr,int n)
    {
         if(n<0)
             return 0;
         if(n==0 || n==1)
             return arr[n];
         if(dp[n]!=-1)return dp[n];
        return dp[n]=arr[n]+min(func(dp,arr,n-1),func(dp,arr,n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(func(dp,cost,n-1),func(dp,cost,n-2));
    }
};
//N-th Tribonacci Number

class Solution {
public:
    
    int func(vector<int>&dp,int n)
    {
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=func(dp,n-1)+func(dp,n-2)+func(dp, n-3);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return func(dp,n);
    }
};