//maximum of subarray (continues) of size k;

#include<iostream>
#include<limits.h>
using namespace std;

void naive(int n ,int k,int arr[])
{
    int ans=INT_MIN;

      for(int i=0;i<=n-k;i++){
        int sum=0;
        for(int j=i;j<k+i;j++)
           sum+=arr[j];
         ans=max(sum,ans);
      }
      cout<<ans<<endl;
}
// void optimized(int n,int k,int arr[])
// {
//   int ans=INT_MIN;
//   int sum=0;

//   for(int i=0;i<k;i++)
//     sum+=arr[i];

//   int l=0,r=k-1;

//   while(r<n-1)
//   {
//     sum-=arr[l++];
//     sum+=arr[++r];
//     ans=max(ans,sum);
//   }
  
//   cout<<ans<<endl;
// }

void optimized(int n,int k,int arr[])
{
  int ans=INT_MIN;
  int sum=0;

  
  int l=0,r=0;

  while(r<n)
  {
    sum+=arr[r];
    if(r-l+1<k)
       r++;
    else if(r-l+1 == k)
    {
      ans=max(ans,sum);
      sum-=arr[l];
      l++;
      r++;
    }    
  }
  
  cout<<ans<<endl;
}
int main()
{
  int n,k;
  cin>>n>>k;

  int arr[n];

  for(int i=0;i<n;i++)
    cin>>arr[i];

  naive(n,k,arr);
  optimized(n,k,arr);

  return 0;
}