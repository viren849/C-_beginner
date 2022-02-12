#include<iostream>
using namespace std;
#include<math.h>
int symbol(int n,int k)
{
    if(n==1 and k==1)
      return 0;
    int mid=pow(2,n-1)/2;
    if(k<=mid)
      return symbol(n-1,k);
    return !(symbol(n-1,k-mid));
}
int main()
{
  int n,k;
  cin>>n>>k;
 int ans=symbol(n,k);
 cout<<ans;
  return 0;
}