

class Solution {
public:

      int dp[300][300];

    int helper(vector<vector<int>>& tri,int i,int j)
    {
         if(i == tri.size()-1 || j == tri.size()-1)
            return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
         int l=INT_MAX;
         int r=INT_MAX;

          if(i+1<tri.size())
          l=tri[i][j]+helper(tri,i+1,j);
          if(i+1<tri.size() && j+1 < tri.size())
         r=tri[i][j]+helper(tri,i+1,j+1);

         return dp[i][j]=min(l,r);
    }


  

    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));

        return helper(triangle,0,0);
    }
};

 int tabulation(vector<vector<int>>& tri)
    {   
        int m=tri.size();
        int n=tri[m-1].size();

        int dp[m][n];
   

      for(int i=m-1;i>=0;i--)
      {
        for(int j=i;j>=0;j--)
        {
            if(i == m-1)
             dp[i][j]=tri[i][j];
           else
           {

                int l=INT_MAX;
                int r=INT_MAX;

                   if(i+1 < m)
                   l=tri[i][j]+dp[i+1][j];

                   if(i+1<m && j+1 < m)
                    r=tri[i][j]+dp[i+1][j+1];

               dp[i][j]=min(l,r);
           }
        }
      }
        
         return dp[0][0];
    }

    //spaceopti...
    int spaceopti(vector<vector<int>>& triangle)
    {
        int m=tri.size();
        int n=tri[m-1].size();

        
   
        vector<int>cur(m,0);
        std::vector<int> frwd(m,0);
      for(int i=m-1;i>=0;i--)
      {
        for(int j=i;j>=0;j--)
        {
            if(i == m-1)
             cur[j]=tri[i][j];
           else
           {

                int l=INT_MAX;
                int r=INT_MAX;

                   if(i+1 < m)
                   l=tri[i][j]+frwd[j];

                   if(i+1<m && j+1 < m)
                    r=tri[i][j]+frwd[j+1];

               cur[j]=min(l,r);
           }
        }
    }
    return frwd[0];
}