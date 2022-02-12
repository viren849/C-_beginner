//rat in  maze
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int vis[150][150];
int diri[4]={0,1,0,-1};
int dirj[4]={1,0,-1,0};
char dir[4]={'R','D','L','U'};

void maze(vector<string>&ans,string tmp,int i ,int j,vector<vector<int>>&mat,int n)
  { 
   
    if(i==n-1 && j==n-1)
     { 
      ans.push_back(tmp);
      return;
     }

    if(i<0||j>=n||j<0||i>=n||vis[i][j])return;
  
      for(int x=0;x<4;x++)
        {
            int ti=i+diri[x];
            int tj=j+dirj[x];
            if( ti>=0 && ti<n && tj>=0 && tj<n &&mat[ti][tj] )
            {
              vis[i][j]=1;
              tmp.push_back(dir[x]);
              maze(ans,tmp,ti,tj,mat,n);
              tmp.pop_back();
              vis[i][j]=0;
            }
        }

  }  
int main()
{
  memset(vis,0,sizeof(vis));
  int n;
  cin>>n;
vector<vector<int>>mat(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>mat[i][j];

  vector<string>ans;
  if(mat[0][0])
    maze(ans,"",0,0,mat,n);
  
  for(string s:ans)
    cout<<s<<endl;
  return 0;
}