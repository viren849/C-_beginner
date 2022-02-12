#include<bits/stdc++.h>
using namespace std;
//KRUSKAL'S ALGORITHM
//GREEDY APPROACH ....
typedef vector<pair<int,pair<int,int>>>viii;
int find_par(int node,vector<int>&par)
{
  if(par[node]<0)
    return node;
  return find_par(par[node],par);
}
void makeunion(int x,int y,vector<int>&par)
{
  int px=find_par(x,par);
  int py=find_par(y,par);
  if(px!=py)
  {
    if(par[px]<par[py])
    {
      par[px]+=par[py];
      par[py]=px;
    }
    else
    {
      par[py]+=par[px];
      par[px]=py;
    }
  }
}
bool comp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
   return a.first<b.first;
}
int main()
{
  int v,e;
  cin>>v>>e;
  viii g,ans;
  vector<int>par(v,-1);
  for(int i=0;i<e;i++)
  {
    int wt,y,z;
      cin>>wt>>y>>z;

    g.push_back({wt,{y,z}});
  }
  sort(g.begin(),g.end());

  for(auto it:g){
     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second;
      cout<<endl;}

    int cost=0;
    for(auto it: g)
    {  
      int w=it.first;
      int u=it.second.first;
      int v=it.second.second;
      if(find_par(u,par)!=find_par(v,par))
      {
        cost+=w;
        ans.push_back({w,{u,v}});
        makeunion(u,v,par);
      }
    }
    cout<<endl;
    for(auto it:ans){
      cout<<it.first<<" "<<it.second.first<<" "<<it.second.second;
      cout<<endl;
    }

    cout<<cost<<" ";
    return 0;
}