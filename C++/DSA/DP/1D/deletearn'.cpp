
//DELETE AND EARN 
//reduce this problem to house robbery...

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int arr[20001];
int func(int v[],int n)
  {
     if(n==0)
        return v[0];
    int l=INT_MIN;

    int r=func(v,n-1);
    if(n>1)
    l=v[n]+func(v,n-2);

    return max(l,r); 
  }
int main()
{
   int n;
   cin>>n;
   vector<int>v(n);
   int mx=INT_MIN;
  
   for(int i=0;i<n;i++)
    {
        cin>>v[i];
        arr[v[i]]+=v[i];
        mx=max(mx,v[i]);
    }

   cout<<func(arr,mx);
}