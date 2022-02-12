
//Burst ballon greedy...
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
          
              return a[1]<b[1];
        
    }
    int findMinArrowShots(vector<vector<int>>& points) {
       
        sort(points.begin(),points.end(),comp);
        
       // for(auto i:points)
       //     cout<<i[0]<<" "<<i[1]<<endl;
        
        int p=points[0][1];
        
        int n= points.size();
        int c=1;
       
        for(int i=1;i<n;i++)
        {
             
            if(points[i][0]>p)
            {
                 c++;  
               p=points[i][1];
            }
            
            
        }
        return c;
        
    }
};