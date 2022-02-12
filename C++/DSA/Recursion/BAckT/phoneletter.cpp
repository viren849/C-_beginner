//phone letter combination
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
 void helper(vector<string>&ans,string tmp,string &d,int index)
 {
        if(index == d.size())
          {
            ans.push_back(tmp);
            return ;
          }

       int n=mappings[d[index]-'2'].length();
        for(int i=0;i<n;i++)
        {
             helper(ans,tmp+mappings[d[index]-'2'][i],d,index+1);
        }
 }
 int main()
 {
    string digit;
    cin>>digit;
    vector<string>ans;

    helper(ans,"",digit,0);
    for(string s:ans)
      cout<<s<<" ";

 }