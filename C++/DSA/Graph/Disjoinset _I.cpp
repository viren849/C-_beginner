#include<bits/stdc++.h>
using namespace std;
//DISJOINT SET....
void make_set()
{

  for(int i=0;i<=n;i++){
     par[i]=i;
     rank[i]=0;
   }

}
int find_par(int node,int par[])
{
  if(node==par[node])
    return node;
//path compression...........
  return par[node]=find_par(par[node],par); 
}
void make_union(int u,int v,int rank[])
{
  u=find_par(u);
  v=find_par(v);
  if(u!=v) //NO NEED TO CHECK FOR IT.....AS RANK WILL GO AUTOMATICALLY THERE..
  {
    if(rank[u]<rank[v])
         par[u]=v;
      else if(rank[v]<rank[u])
        par[v]=u;
      else{
         par[v]=u;
         rank[u]++;
      }
  }
}
int main()
{
  int n=5;

  return 0;
}