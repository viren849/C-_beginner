#include<bits/stdc++.h>
using namespace std;
//topological sort
void toposort(stack<int>&ans,vector<int>g[],vector<bool>&vis,int i)
{
      vis[i]=1;
      //checking for adjacency........
       for(auto it:g[i])
         if(!vis[it])
            toposort(ans,g,vis,it);
     ans.push(i);
}
int main()
{
  int v,e;
  cin>>v>>e;
  vector<int>g[v+1];

  for(int i=0;i<e;i++)
  {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
  }

  stack<int>ans;
  vector<bool>vis(v,0);
  for(int i=0;i<v;i++)
    if(!vis[i])
    toposort(ans,g,vis,i);
  while(!ans.empty()){
    cout<<ans.top()<<" ";
    ans.pop();
  }

  return 0;
}