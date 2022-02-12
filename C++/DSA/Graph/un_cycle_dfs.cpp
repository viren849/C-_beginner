//cycle detection dfs undirected...
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
#include<queue>
bool checkcycle(int st,int par,vector<bool>&vis,vector<int>g[])
{
    vis[st]=1;
    
    for(auto it:g[st])
      if(!vis[it])
        return checkcycle(it,st,vis,g);
      else
        if(it!=par) return true;
     return false; 
}
bool cycle(vector<int>g[],int n)
{
  vector<bool>vis(n);
  for(int i=0;i<n;i++)
    if(!vis[i])
      if(checkcycle(i,-1,vis,g))
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
