#include<bits/stdc++.h>
using namespace std;
//REPRESENTATION OF UNDIRECTED GRAPH.....

void bfs(int i,vector<int>&ans,vector<int>g[],vector<bool>&vis)
{
     queue<int>q;
     q.push(i);
     vis[i]=1;

     while(!q.empty())
     {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: g[i])
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
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
            bfs(i,ans,g,vis);

     for(auto it: ans)
        cout<<it<<" ";
    return 0;            
}