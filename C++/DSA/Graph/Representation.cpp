#include<bits/stdc++.h>
using namespace std;
//REPRESENTATION OF UNDIRECTED GRAPH.....
void Adjacency(int v,int e)
{
    int A[v][v];
    memset(A,0,sizeof(A));
    for(int i=0;i<e;i++)
    {
        int x,y;
         cin>>x>>y;
         A[x][y]=1;
         A[y][x]=1;
    }
   
   for(int i=0;i<v;i++)
   {
    for(int j=0;j<v;j++)
        cout<<A[i][j]<<" ";
    cout<<endl;
   }
}
int main()
{
     int v,e;
     cin>>v>>e;
     // std::vector<int>gr[v+1];

     // for(int i=0;i<e;i++)
     // {
     //    int x,y;
     //     cin>>x>>y;
     //     gr[x].push_back(y);
     //     gr[y].push_back(x);
     // }   

     //  for(auto i:gr){
     //   for(auto it:i)
     //    cout<<it<<" ";
     //     cout<<endl;
     // }

    return 0;            
}