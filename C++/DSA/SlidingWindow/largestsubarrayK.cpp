  
//largest subarray of sum k..

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 

 
int main()
{
  
 int n;
 cin>>n;
 ll arr[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];

 ll sum;
 cin >> sum;

unordered_map<int,int>mp;

int prefix=0;
int count=0;
int len=0;
  for(int i=0;i<n;i++)
  {   
    prefix+=arr[i];

    if(prefix == sum)
    {
         count++;
         len=i+1;
    }
    if(mp.find(prefix-sum)!=mp.end())
    {
         int lastindex=mp[prefix-sum];
         count++;
         len=max(len,i-lastindex);
         
    }
    if(mp.find(prefix)==mp.end())
    {
      mp[prefix]=i; //if u not check the already present prefix the u will end up updating 
    }               //the prefix and index which result in min window size..
  }                //EG: 3 4 7 0 -3 1 4 2  and 3 4 7 0 0 1 4 2
  
  cout<<len <<" "<<count<<" ";

   // mp[4]=2;
   // mp[4]=3;
   // mp[4]=2;
   // mp[9]=2;
   // mp[3]=3;

   // for(auto i:mp)
   //  cout<<i.first<<" "<<i.second<<endl;
   return 0;
}