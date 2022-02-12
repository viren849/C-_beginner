// permutation with spaces ......
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void recursion1(int index,string &s,vector<string>&ans,string tmp)
{
    if(index >= s.length())
    {
      ans.push_back(tmp);
      return;
    }
   
    recursion1(index+1,s,ans,tmp+" "+s[index]);
    recursion1(index+1,s,ans,tmp+s[index]);

}

void recursion(int index,string &s,vector<string>&ans,string tmp)
 {
      
     if(index >= s.length())
    {
      ans.push_back(tmp);
      return;
    }
    tmp.push_back(' ');
    recursion1(index+1,s,ans,tmp+s[index]);
    tmp.pop_back();
    recursion1(index+1,s,ans,tmp+s[index]);

 }

 void recursion12(int index,string &s,vector<string>&ans,string tmp)
 {
      
     if(index >= s.length())
    {
      ans.push_back(tmp);
      return;
    }
    tmp.push_back(' ');
    tmp.push_back(s[index]);
    recursion1(index+1,s,ans,tmp);
    tmp.pop_back();
    tmp.pop_back();
    tmp.push_back(s[index]);
    recursion1(index+1,s,ans,tmp);   //recursion1(index+1,s,ans,tmp+s[index]); 

 }

void recursion2(int index,string &s,vector<string>&ans,string tmp)
{
      
          
        for(int i=index;i<s.length();i++)
        {
        // if(i > index and s[i] == s[i-1])continue ;
           recursion2(i+1,s,ans,tmp+" "+s[i]);
           tmp+=s[i];
        }
       ans.push_back(tmp);
}

int main()
{
  string s;
  cin>>s;
  vector<string>ans;

  string tmp;
  tmp.push_back(s[0]);

  recursion12(1,s,ans,tmp);

  sort(ans.begin(),ans.end());

  for(string s: ans)
    cout<<s<<endl;

  return  0 ;
}
