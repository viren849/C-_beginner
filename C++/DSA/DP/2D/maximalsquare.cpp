//MAXIMAL SQUARE...........
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=n>0?matrix[0].size():0;
       
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
         int maxi=0; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {  
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    maxi=max(maxi,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return maxi*maxi;
    }
};

//Space optimization..
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=n>0?matrix[0].size():0;
       
       vector<int>cur(m+1,0);
       vector<int>prev(m+1,0);
         int maxi=0; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {  
                   cur[j]=1+min(prev[j],min(prev[j-1],cur[j-1]));
                    maxi=max(maxi,cur[j]);
                }
                else cur[j]=0;
            }
            prev=cur;
        }
        return maxi*maxi;
    }
};