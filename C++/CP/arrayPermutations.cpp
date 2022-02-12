
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n=7;
    int arr[n];

    for(int i=0;i<n;i++)
      cin>>arr[i];
   
   cout<<arr[0]<<" "<<arr[1]<<" "<<arr[n-1]-arr[0]-arr[1];
   cout<<endl;
  }
  return 0;
}