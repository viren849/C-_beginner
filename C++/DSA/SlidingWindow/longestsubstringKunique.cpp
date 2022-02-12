  
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
   int k;
   cin >> k;
   
   unordered_map<char,int>mp;
   int i=0;
   int j=0;
   int len=-1;
   while(i<s.length())
     {
        mp[s[i]]++;
       // cout<<mp.size()<<" ";
        if(mp.size()<k)
          i++;
        else if(mp.size()==k)
          {
            len=max(len,i-j+1);
            i++;
          }
        else
        {
          while(mp.size()>k)
            {
              mp[s[j]]--;
              if(mp[s[j]]== 0)
                mp.erase(s[j]);
              j++;
              
            }
            i++;
        }
        
     }
     cout<<len<<endl;
   return 0;
}