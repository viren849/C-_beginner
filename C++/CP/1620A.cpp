#include<iostream>
using namespace std;
#include<string>

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int N=0,S=0;
    for(char c:s)
      if(c=='E')
        S++;
      else N++;
  if(N==1)
    cout<<"no";
  else cout<<"yes";
  cout<<endl;
}
  return 0;
}