#include<iostream>
using namespace std;
#include<vector>
void prit(vector<int>&v)
{
  for(int i:v)
    cout<<i<<" ";
  cout<<endl;
}
void recurse(vector<int>&v,int n)
{
  if(n==0)
  {
    prit(v);
    return;
  }
  for(int i=0;i<3;i++)
     {
        v.push_back(i);
        recurse(v,n-1);
        v.pop_back();
     }
}
int main()
{
  int n;
  cin>>n;
  vector<int>v;
  recurse(v,n);
}