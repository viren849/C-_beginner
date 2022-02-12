
//gcd 
#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


int main()
{
  int t;
  cin>>t;
  
  while(t--){
    long long n;
    cin>>n;

    if(n%2==0)
    {
      cout<<n-3 <<" "<<"2 1"<<endl;
    }
    else
    {
      long long t=n-1;

      long long a;
      a=(t-1)/2;
      if(a%2 == 0)
      {
          cout<<a-1<<" "<<n-a<<" "<<1<<endl;
      }
      else{
             cout<<a<<" "<<a+2<<" "<<1<<endl;
      }

    }
  }
  return 0;
}