#include<vector>
#include<iostream>
#include<utility>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>v(n);
  //let first be the end time and second be the start time..
  for(int i=0;i<n;i++)
  {
    cin>>v[i].first>>v[i].second;
  }
   sort(v.begin(),v.end());
   int end=-1;
   int p=1;
   for(int i=0;i<n;i++)
   {
    if(v[i].second>=end)
      end=v[i].first;
    else p++;
   }
   cout<<p;
   return 0;
}