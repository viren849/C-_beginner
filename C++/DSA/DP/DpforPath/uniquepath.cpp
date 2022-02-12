

class Solution {
public:
    int dp[101][101];
    int helper(int m,int n)
    {
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n] !=-1 ) return dp[m][n];
        
       return  dp[m][n]=helper(m-1,n)+helper(m,n-1);   
        
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return helper(m-1,n-1);
    }
};
class Solution {
public:
    int dp[101][101];
    int helper(vector<vector<int>>& mat,int m,int n)
    {
        if(m==0 and n==0)
            return 1;
        if(m<0 or n<0) return 0;
        
         if(dp[m][n] != -1) return dp[m][n];
        
        int l=0,r=0;
        if(n-1 >=0 and mat[m][n-1] != 1)
           l= helper(mat,m,n-1);
        if(m-1 >=0 and mat[m-1][n] != 1)
           r= helper(mat,m-1,n);
        return dp[m][n]=l+r;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& d) {
        memset(dp,-1,sizeof(dp));
        int m=d.size();
        int n=d[0].size();
        if(n-1>=0 and m-1 >=0 and d[m-1][n-1] != 1)
        return helper(d,m-1,n-1);
        return 0;
    }
};