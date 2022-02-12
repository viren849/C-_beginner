//ALLOWED TO MOVE ONLY right,down

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[150][150];
int diri[]={0,1,0,-1};
int dirj[]={1,0,-1,0};
char dir[]={'R','D','L','U'};

int ediri[]={0,1,0,-1,-1,1,-1,1};
int edirj[]={1,0,-1,0,-1,-1,1,1};
string edir[]={"R ","D ","L ","U ","Lu ","Ld ","Ru ","Rd "};

void recur(vector<string>&ans,string tmp,int n,int m,int i,int j)
{
       if(i>=n || j>=m)return;
         if(n-1==i && m-1==j )
         {
          ans.push_back(tmp);
          return;
         }
   if(!vis[i][j]){
    vis[i][j]=1;
    recur(ans,tmp+'R',n,m,i,j+1);
    vis[i][j]=0;
     vis[i][j]=1;
     recur(ans,tmp+'D',n,m,i+1,j);
     vis[i][j]=0;
    }
}
void recur1(vector<string>&ans,string tmp,int n,int m,int i,int j)
{
       if(i>=n || j>=m)return;
         if(n-1==i && m-1==j )
         {
          ans.push_back(tmp);
          return;
         }
  for(int index=0;index<2;index++ )
  {

      if(!vis[i][j])
      {
        vis[i][j]=1;
         recur1(ans,tmp+dir[index],n,m,i+diri[index],j+dirj[index]);
        vis[i][j]=0;
      }
  }

}
//for 4 direction.....
void recur2(vector<string>&ans,string tmp,int n,int m,int i,int j)
{
       if(i>=n || j>=m || i<0 || j<0 || vis[i][j])return;
         if(n-1==i && m-1==j )
         {
          ans.push_back(tmp);
          return;
         }
  for(int index=0;index<4;index++ )
  {

      if(!vis[i][j])
      {
        vis[i][j]=1;
         recur2(ans,tmp+dir[index],n,m,i+diri[index],j+dirj[index]);
        vis[i][j]=0;
      }
  }
}

//for 8 direction....
void recur3(vector<string>&ans,string tmp,int n,int m,int i,int j)
{
       if(i>=n || j>=m || i<0 || j<0)return;
         if(n-1==i && m-1==j )
         {
          ans.push_back(tmp);
          return;
         }
  for(int index=0;index<8;index++ )
  {

      if(!vis[i][j])
      {
        vis[i][j]=1;
         recur3(ans,tmp+edir[index],n,m,i+ediri[index],j+edirj[index]);
        vis[i][j]=0;
      }
  }
}
 int main()
 {
  int n,m;
  cin>>n>>m;
  vector<string>ans;
   memset(vis,0,sizeof(vis));
  recur3(ans,"",n,m,0,0);

  for(string s: ans)
    cout<<s<<endl;
 }