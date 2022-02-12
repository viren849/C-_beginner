#include<iostream>
using namespace std;
#include<string>
#include<limits.h>
#include<algorithm>

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     long n;
     cin>>n;
     long arr[n];
     for(int i=0;i<n;i++)
      cin>>arr[i];
    sort(arr,arr+n);
    cout<<(arr[n-1]-arr[0])*arr[n-2]<<endl;
  }
  return 0;
}