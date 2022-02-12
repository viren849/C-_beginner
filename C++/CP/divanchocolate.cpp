//Divan and chocolate
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
int main()
{  
  int t;
  cin>>t;
  while(t--){
   int n,l,r,k;
   cin>>n>>l>>r>>k;
   int arr[n];

   for(int i=0;i<n;i++)
    cin>>arr[i];

   sort(arr,arr+n);
   int c=0;
   for(int i=0;i<n;i++)
    if(arr[i]>=l && arr[i]<=r && k>=arr[i])
    {
      c++;
      k-=arr[i];
    }

    cout<<c<<endl;
  }
  return 0;
}
