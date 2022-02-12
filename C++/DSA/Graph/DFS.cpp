#include<bits/stdc++.h>
using namespace std;
//REPRESENTATION OF UNDIRECTED GRAPH.....

void dfs(int i,vector<int>&ans,vector<int>g[],vector<bool>&vis)
{
    ans.push_back(i);
    vis[i]=1;
    for(auto it: g[i])
        if(!vis[it])
        {
            dfs(it,ans,g,vis);
        }  
}

int main()
{
     int v,e;
     cin>>v>>e;
     vector<int>g[v];
     for(int i=0;i<e;i++)
     {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
     }


     vector<int> ans;
      vector<bool>vis(v,0);
      
      for(int i=0;i<v;i++)
        if(!vis[i])
            dfs(i,ans,g,vis);

     for(auto it: ans)
        cout<<it<<" ";
    return 0;            
}