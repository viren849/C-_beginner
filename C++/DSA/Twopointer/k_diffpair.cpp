// 532. K-diff Pairs in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

 //two mwthod can be done one is nlogn 
  // in which sort the arr and i and at the right we will find i+x using
 // binARY SEarch...

// using hashmap...
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
     cin>>v[i];
   int k;
   cin >> k;
  
  unordered_map<int,int>st;
  for(int i:v)
     st[i]++;
 int ans=0;
 int ans2=0;
   for(auto i:st )
     {
      if(st.find(i.first+k)!=st.end())ans++;
      if(st[i.first]>1)ans2++;
     }
  if(k!=0)
  cout<<ans;
   else 
      cout<<ans2;
}