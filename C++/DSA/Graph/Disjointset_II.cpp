#include<bits/stdc++.h>
using namespace std;
void makeset()
{
  vector<int>parent(n,-1);
}
int find_par(int node)
{
  if(parent[node]<0)
    return parent[node];
  return find_par(parent[node]);
}
void makeunion(int u,int v)
{
  int pu=find_par(u);
  int pv=find_par(v);
  if(pu!=pv)
  {
      if(parent[pu]<parent[pv])
      {
        parent[pu]+=parent[pv];
        parent[pv]=pu;
      }
      else
      {
        parent[pv]+=parent[pu];
        parent[pu]=pv;
      }
  }
}
{
  int n=5;

}