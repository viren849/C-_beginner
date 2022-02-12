#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ispalindrome(string s)
{
  int n=s.length();

  if(n==1)return true;

  for(int i=0,j=n-1;i<j;i++,j--)
    if(s[i]!=s[j])return false;

  return true;
}

void solve(vector<vector<string>>&ans,string &s,int start,vector<string> tmp)
{
      

     if(start == s.length())
       ans.push_back(tmp);

      for(int i=start;i<s.length();i++)
      {
        string tmp2=s.substr(start,i-start+1);
         if(ispalindrome(tmp2))
         { 
           tmp.push_back(tmp2);
           solve(ans,s,i+1,tmp);
           tmp.pop_back();  
         }
      }
   
}
int main()
{
  string s;
  cin>>s;
  vector<vector<string>>ans;

  solve(ans,s,0,{""});

    for(auto s : ans)
      {
        for(string c :s)
          cout<<c<<" ";
        cout<<endl;
      }
}