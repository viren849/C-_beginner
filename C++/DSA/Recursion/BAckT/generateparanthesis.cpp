//generate valid paranthesis..
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//logic 
 //if the open'(' present then only i can add the ')' bracket ....
void helper(vector<string>&ans,int n ,int open,int close,string tmp)
{
  if(open == 0 && close == 0)
  {
    ans.push_back(tmp);
    return;
  }
     
     if(open)
     {
        tmp.push_back('(');
        helper(ans,n,open-1,close,tmp);
        tmp.pop_back();
     }
     if(close > open and close)
     {
      tmp.push_back(')');
        helper(ans,n,open,close-1,tmp);
        tmp.pop_back();
     }
}
int main()
{
  int n;
  cin>>n;
  vector<string>ans;
  helper(ans,n,n,n,"");
  for(string s:ans)
    cout<<s<<endl;
  return 0;
}