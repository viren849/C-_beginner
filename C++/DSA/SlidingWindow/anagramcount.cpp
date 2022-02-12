
//anagram count in string

#include<iostream>
#include<limits.h>
#include<vector>
#include<unordered_map>
using namespace std;

void usinghash(string &s,string &p)
{

    vector<long long>parr(26,0);
    vector<long long>sarr(26,0);

    long long n=s.size();
    long long k=p.size();

    for(long i=0;i<k;i++)
      parr[p[i]-'a']++;
    
    long long c=0;
    long long l=0,r=0;

    while(r<n)  
    {
      sarr[s[r]-'a']++;

      if(r-l+1<k)
        r++;
      else if(r-l+1 == k)
      {
        
        if(parr==sarr)
          c++;
        sarr[s[l]-'a']--;
        l++;
        r++;
      }
       
    }
    cout<<c<<endl;
}
void usingmap(string &s,string &p)
{

    unordered_map<char,int>mp;

    long long n=s.size();
    long long k=p.size();

    for(long i=0;i<k;i++)
     mp[p[i]]++;
    
    long long c=0,count=mp.size();
    long long l=0,r=0;
    
    while(r<n)  
    {
      
      if(mp.find(s[r])!=mp.end())
       {   mp[s[r]]--;
          if(mp[s[r]]==0)count--;
        }

      if(r-l+1<k)
        r++;
      else if(r-l+1 == k)
      {
        if(count==0)
          c++;
        
        if(mp.find(s[l])!=mp.end())
         {
          mp[s[l]]++;
          if(mp[s[l]]==1)
          count++;
        }

        l++;
        r++;
      }
       
    }
    cout<<c<<endl;
}
int main()
{
  int t;
  cin>>t;
  while(t--){
    
    string s,p;
    cin>>s>>p;
    usinghash(s,p);
    usingmap(s,p);
  }
  return 0;
}