// print the subsequences....
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// take or not (choices)....
 void recursion(int i,string &s,vector<string>&ans,string temp)
 {
    
     if(i >= s.length())
        {
          ans.push_back(temp);
          return;
        }
        recursion(i+1,s,ans,temp+s[i]);
         
        recursion(i+1,s,ans,temp);
 }

 void recursion1(int i,string &s,vector<string>&ans,string temp)
 {
    
     if(i >= s.length())
        {
          ans.push_back(temp);
          return;
        }
        temp.push_back(s[i]); 
        recursion(i+1,s,ans,temp);//include
        temp.pop_back();          // this is backtracking ...
        recursion(i+1,s,ans,temp);
 }

void recursion2(int index,string &s,vector<string>&ans,string temp)
 {
       
       ans.push_back(temp);   
        for(int j=index;j<s.length();j++)
        {
             //temp.push_back(s[j]);
             recursion2(j+1,s,ans,temp+s[j]);
             //temp.pop_back(); 
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
