//way too long..
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
int main()
{  
   int t;
   cin>>t;
   while(t--)
   {
   	string s;
   	cin>>s;
   	int len=s.size();
   	if(len>10){
   	 len-=2;
   	 cout<<s[0]<<len<<s[len+1]<<endl;
   	}
   	else
   		cout<<s<<endl;
   }
}