  
//longest substring without repeating characters.....

#include<iostream>
#include<limits.h>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 

 void usingmap(string &s)
 {
     unordered_map<char,int>mp;
   
     int l=0,r=0,len;
     int mx=INT_MIN;
     int n=s.length();
     while(r<n)
     {
         if(mp.find(s[r])!=mp.end())
         {                             // lindex         l         r    
            int lindex=mp[s[r]];
              if(lindex >= l)
                 l=lindex+1;
         }
         mp[s[r]]=r;
         len=r-l+1;
         mx=max(len,mx);
         r++;
     }
     cout<<mx<<endl;
 }
int main()
{
  
   string s;
   cin>>s; 

   unordered_set<char>st;
   
     int l=0,r=0,len;
     int mx=INT_MIN;
     int n=s.length();

     while(r<n)
     {

        while(st.find(s[r])!=st.end())
           {
             st.erase(s[l]);
             l++;
           }
           st.insert(s[r]);
           len=r-l+1;                 //complexity 2n..
       mx=max(mx,len);
       r++;
     }
     cout<<mx<<endl;
     usingmap(s);
   return 0;
}