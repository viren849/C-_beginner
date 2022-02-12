// Minimum Path Sum

    int dp[202][202];
    int helpermemo(vector<vector<int>>& grid,int m,int n)
    {
        if(m==0 and n==0) return grid[0][0];
        
        if(dp[m][n]!=-1)return dp[m][n];
        int l=INT_MAX;
        int r=INT_MAX;
        if(m-1>=0)
         l=grid[m][n]+helper(grid,m-1,n);
        if(n-1>=0)
         r=grid[m][n]+helper(grid,m,n-1);
        
        return dp[m][n]=min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        return helpermemo(grid,m-1,n-1);
    }

    int Tabulation(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();

        dp[0][0]=grid[0][0];
         
         for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];

          for(int i=1;i<n;i++)
             dp[0][i]=dp[0][i-1]+grid[0][i];

        for(int i=1;i<m;i++)
          {

            for(int j=1;j<n;j++)
             {
               int l=INT_MAX,r=INT_MAX;

               if(i-1>=0)l=grid[i][j]+dp[i-1][j];
               if(j-1>=0)r=grid[i][j]+dp[i][j-1];
               
               dp[i][j]=min(l,r);
             }

          }
          return dp[m-1][n-1];
    }

//always try to fill the table then u will understand to space optimize
     //Like in this case 
    //when we calculated for the prev (at what basis i shld fill this array)
// and also for the cur which keeps on changing after the 
    // every iteration.......
    int spaceopti(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>prev(n,0);
        vector<int>cur(n,0);

        prev[0]=grid[0][0];
         
         for(int i=1;i<n;i++)
           prev[i]=prev[i-1]+grid[0][i];

          
             //cur[0]=prev[0]+grid[1][0];

        for(int i=1;i<m;i++)
          {

           cur[0]=prev[0]+grid[i][0];
            for(int j=1;j<n;j++)
             {
               int l=INT_MAX,r=INT_MAX;

               if(i-1>=0)l=grid[i][j]+prev[j];
               if(j-1>=0)r=grid[i][j]+cur[j-1];
               
               cur[j]=min(l,r);
             }
             prev=cur;
          }
          return prev[n-1];
    }
    //we can also further optimise it by using only  1 vector instead of 2....
    refer...
    
    https://leetcode.com/problems/minimum-path-sum/discuss/23457/C%2B%2B-DP