#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
  }
  int ans=v[0].second;
  int mx=ans;
  for(int i=1;i<n;i++)
  {
    ans+=v[i].second;
    ans-=v[i].first;
    if(mx<ans)
      mx=ans;
  }
  cout<<mx<<endl;
}