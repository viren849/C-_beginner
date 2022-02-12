//isomorphic strings


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
  string s,p;
  cin>>s>>p;
  
  int n=s.length();
  int z=p.length();
   
   if(n!=z) return 0;

   unordered_map<char,char>mp;
   unordered_map<char,bool>wd;
  
  for(int i=0;i<n;i++)
  {
    if(mp.find(s[i]) == mp.end())
        {
         if( wd[t[i]] == 0) return 0;
          mp[s[i]] = p[i];
          wd[t[i]]=1;
        }
     else
     {
               if(t[i]!=mp[s[i]])
                return false;
     }
  }


  return 0;

}