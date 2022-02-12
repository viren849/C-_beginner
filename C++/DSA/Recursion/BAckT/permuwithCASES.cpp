//permutation with the cases
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
	if(s[index]>='a' && s[index]<='z')
		tmp.push_back(s[index] - ('a'-'A'));
	else	
		tmp.push_back(s[index] + ('a'-'A'));

	recursion(index+1,ans,s,tmp);

	  tmp.pop_back();
	tmp.push_back(s[index]);
	recursion(index+1,ans,s,tmp);
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
	if(s[index]>='a' && s[index]<='z')
		 c=s[index]-('a'-'A');
	else	
		c=s[index] + ('a'-'A');
	
	recursion1(index+1,ans,s,tmp+c);

	recursion1(index+1,ans,s,tmp+s[index]);
}

void recursion2(int index,vector<string>&ans,string &s,string tmp)
{
	for(int i=index;i<s.length();i++)
	{
		 if(s[i]>='a' && s[i]<='z')
		tmp.push_back(s[i] - ('a'-'A'));
	else	
		tmp.push_back(s[i] + ('a'-'A'));

	recursion2(i+1,ans,s,tmp);
	  tmp.pop_back();
	  tmp+=s[i];
	}
	ans.push_back(tmp);
}

void recursion3(int index,vector<string>&ans,string &s,string tmp)
{
	for(int i=index;i<s.length();i++)
	{
		 char c;
       if(s[index]>='a' && s[index]<='z')
		 c=s[index]-('a'-'A');
	else	
		c=s[index] + ('a'-'A');

	recursion3(i+1,ans,s,tmp+c);
	  tmp+=s[i];
	}
	ans.push_back(tmp);
}
int main()
{
	string s;
    cin>>s;
    vector<string>ans;
    recursion3(0,ans,s,"");
    for(string c:ans)
    	cout<<c<<endl;
  return 0;
}