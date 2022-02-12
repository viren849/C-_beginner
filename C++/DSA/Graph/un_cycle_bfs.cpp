//detect cycle in graph bfs undirected graph.......
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
#include<queue>
bool checkcycle(int st,vector<bool>&vis,vector<int>g[])
{
    queue<pair<int,int>>q;
    q.push({st,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int par=q.front().second;
        q.pop();

        for(auto it:g[node])
        {
          if(!vis[it])
          {
            vis[it]=true;
            q.push({it,node});
          }
          else
             if(par!=it)
              return true;
        }
    }
    return false;
}
bool cycle(vector<int>g[],int n)
{
  vector<bool>vis(n);
  for(int i=0;i<n;i++)
    if(!vis[i])
      if(checkcycle(i,vis,g))
        return true;

  return false;
}
int main()
{  
  int e,n;
  cin>>e>>n;
  vector<int>g[n];

  for(int i=0;i<e;i++)
  {
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  if(cycle(g, n))
   cout<<"yes";
  else 
    cout<<"no";
  return 0;
}
