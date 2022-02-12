// print the subsequences....
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void recursion2(int index,string &s,vector<string>&ans,string tmp)
{
        ans.push_back(tmp);
        for(int i=index;i<s.length();i++)
        {
         if(i > index and s[i] == s[i-1])continue ;
           recursion2(i+1,s,ans,tmp+s[i]);
        }
}

int main()
{
  string s;
  cin>>s;
  vector<string>ans;
  recursion2(0,s,ans,"");

sort(ans.begin(),ans.end());

  for(string s: ans)
    cout<<s<<endl;

  return  0 ;
}
