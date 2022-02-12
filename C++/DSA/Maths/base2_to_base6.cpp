  
#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 


vector<int>solution(vector<bool> base2)
{
         int l=base2.length();
       
       int decimal=0;
      
     for(int i=0, j=l-1;j>=0;j--,i++)
          decimal+=(pow(2,i)*(base2[j]-'0'));
      

      vector<int>ans;
 
 
      while(y>0)
      {
          int rem=y%6;
          y/=6;
          ans.push_back(rem);
      }
      
      reverse(ans.begin(),ans.end());
      



      return ans;

      

}
 int base(string &s)
 {
     int l=s.length();
       
       int decimal=0;
      
     for(int i=0, j=l-1;j>=0;j--,i++)
          decimal+=(pow(2,i)*(s[j]-'0'));
      return decimal;
 }
 string six_base(int y)
 {
  string res;
      while(y>0)
      {
          int rem=y%6;
          y/=6;
          res.push_back(rem + '0');
      }
      
      reverse(res.begin(),res.end());
      return res;
 }
int main()
{
    string s;
    cin>>s;

    int y=base(s);
    cout<<y<<endl;
     cout<<six_base(y);
   return 0;
}