  
//longest substring with atmost k unique characters

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
  
   string s;
   cin>>s;
   int k;
   cin >> k;
   
   unordered_map<char,int>mp;
     int l=0,r=0;
     int n=s.length();
   
   int ans=INT_MIN;

     while(r<n)
     {
          mp[s[r]]++;                            //mp[s[r]]=r;
          if(mp.size()<=k)
          {
              int len=r-l+1;
              ans=max(len,ans);
          }
          else
          {
            while(mp.size()>k)              //int lindex=mp[s[l]];
             {                              // if(l<=lindex)l=lindex+1;
              mp[s[l]]--;
             if(mp[s[l]]==0)
               mp.erase(s[l]);
             l++;
           }
          }
          r++;
     }
      cout<<ans<<endl;
     optimization(s,k);
   return 0;
}