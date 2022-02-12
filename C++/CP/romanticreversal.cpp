#include<iostream>
using namespace std;
#include<string>
#include<limits.h>
#include<algorithm>
void reverse(string &s,int k)
{
    int i=0;
    int j=k;
    while(i<j)
    {
      swap(s[i],s[j]);
      i++;
      j--;
    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i=0;
    while(i<k-1){
      reverse(s,k-i-1);
      i++;
    }
    cout<<s<<endl;
  }
  return 0;
}