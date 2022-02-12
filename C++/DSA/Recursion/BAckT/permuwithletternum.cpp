//permutation with the cases and number
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void recursion(int index,vector<string>&ans,string &s,string tmp)
{

	if(index >= s.length())
		 {
		 	ans.push_back(tmp);
		 	return;
		 }

if(s[index]>='0' && s[index]<='9')
{
    tmp.push_back(s[index]);
    recursion(index+1,ans,s,tmp);

}else {
	if(s[index]>='a' && s[index]<='z')
		tmp.push_back(s[index] - ('a'-'A'));
	else 
		tmp.push_back(s[index] + ('a'-'A'));     

	recursion(index+1,ans,s,tmp);

	  tmp.pop_back();
	  tmp.push_back(s[index]);

	recursion(index+1,ans,s,tmp);
   }

    
}
//without backtracking....
void recursion1(int index,vector<string>&ans,string &s,string tmp)
{
	if(index >= s.length())
		 {
		 	ans.push_back(tmp);
		 	return;
		 }
		 char c;
   if( !isdigit(s[index]))
	 {
	   if(s[index]>='a' && s[index]<='z')
		 c=s[index]-('a'-'A');
	   else	
		c=s[index] + ('a'-'A');
	
	  recursion1(index+1,ans,s,tmp+c);

	  recursion1(index+1,ans,s,tmp+s[index]);
	}
	else recursion1(index+1,ans,s,tmp+s[index]);
}
int main()
{
	string s;
    cin>>s;
    vector<string>ans;
    recursion2(0,ans,s,"");
    for(string c:ans)
    	cout<<c<<endl;
  return 0;
}