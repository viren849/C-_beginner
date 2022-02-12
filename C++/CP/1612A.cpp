#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    if((x+y) % 2== 0)
    {
        if(x%2==0)
          cout<<x/2<<" "<<y/2<<endl;
        else
          cout<<(x-1)/2<<" "<<(y+1)/2<<endl;
    }
    else
    {
      cout<<"-1 -1"<<endl;
    }
  }
  return 0;
}