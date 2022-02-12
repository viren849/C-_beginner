//first -ve no. in window size k

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void naive(int n ,int k,int arr[])
{
      for(int i=0;i<=n-k;i++){
        int flag=1;
        for(int j=i;j<k+i;j++)
           if(arr[j]<0){
             cout<<arr[j]<<" ";
             flag=0;
             break;
           }
         if(flag)
           cout<<0<<" ";
      }
}
void optimized(int n,int k,int arr[])
{
  vector<int>v;

  int l=0,r=0,j=0;

  while(r<n)
  {
    if(arr[r]<0)
      v.push_back(arr[r]);

    if(r-l+1<k)
       r++;
    else if(r-l+1 == k)
    {
      if(j>=v.size())
        cout<<0<<" ";
      else
      {
        cout<<v[j]<<" ";
        if(v[j]==arr[l])
          j++;
      }
      
      l++;
      r++;
    }    
  }
  
}
int main()
{
  int t;
  cin>>t;
  while(t--){
  int n,k;
  cin>>n>>k;

  int arr[n];

  for(int i=0;i<n;i++)
    cin>>arr[i];

  naive(n,k,arr);
  cout<<endl;
  optimized(n,k,arr);
  cout<<endl;
}
  return 0;
}