  
//longest k unique character substring....

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
   string t;
   cin>>t;
   
   unordered_map<char,int>mp;

   for(char c: t)
     mp[c]++;

   int count=mp.size();
   int k=t.length();
   int n=s.length();
   int l=0,r=0,x=0,y=0;
  int mn=INT_MAX;
  int len;
 
 string ans;
    while(r<n)
    {
        if(mp.find(s[r])!=mp.end())
        {
            mp[s[r]]--;
            if(mp[s[r]] == 0) count--;
        }
    
           while(count==0)
              {
                len=r-l+1;
                 if(mn>len)
                 {
                  mn=len;
                  x=l;
                  y=r;
                 }
                 if(mp.find(s[l])!=mp.end())
                   {
                    mp[s[l]]++;
                    if(mp[s[l]] == 1) count++;
                  }
                  l++;
              }
           r++;
        

    }

    if(x==0 and y==0 and mn==INT_MAX)
      ans="";
    else
        {
          while(x<=y)
          ans.push_back(s[x++]);
        }
    cout<<ans;
   return 0;
}