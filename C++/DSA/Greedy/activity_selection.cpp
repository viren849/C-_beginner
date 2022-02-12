//Activity selection problem...
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
int main()
{  
    int n;
    cin>>n;
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++)
      {
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
      } 
      sort(v.begin(),v.end());
   int count=1;
   // for(int i=0;i<n;i++)
   //   cout<<v[i].second<<" "<<v[i].first<<endl;

      int end=v[0].first;
      for(int i=1;i<n;i++)
      {
        if(v[i].second>end){
            count++;
            end=v[i].first;
        }
      }
      cout<<count<<" ";
    return 0;

}