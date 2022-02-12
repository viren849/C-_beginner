
//849. Maximize Distance to Closest Person

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 


void usingarray(int arr[],int n)
{
    vector<int>larr(n,0);
    vector<int>rarr(n,0);
  
  //finding each distance from left side 

    for(int i=0;i<n;i++)
      if(arr[i]==1)larr[i]=0; //i.e already  a person is sitting 
    else if(i>0)
      larr[i]=larr[i-1]+1;

//similary for right array..
    for(int i=n-1;i>=0;i--)
       if(arr[i] == 1) rarr[i]=0;
    else if(i < n-1) rarr[i]=rarr[i+1] +1;

    for(int i=0;i<n;i++)
      cout<<larr[i]<<" ";

    cout<<endl;

     for(int i=0;i<n;i++)
      cout<<rarr[i]<<" ";
      
      cout<<endl;

      int ans=0;

      for(int i=0;i<n;i++)
        if(arr[i] == 0)
          ans=max(ans,min(larr[i],rarr[i]));

        cout<<ans;
        cout<<endl;
}
void nospace(int arr[] , int n)
{

   int ans=0,z=0;
    for(int i=0;i<n;i++){
      if(arr[i] == 1)
        z=0;
      else z++;
      ans=max(ans,z);
    }
    ans=(ans+1)/2;

   for(int i=0;i<n;i++)
    if(arr[i]==1)
    {
      ans=max(i,ans);
      break;
    }

    for(int j=n-1;j>=0;j--)
    {
      
      if(arr[j] == 1){
        ans=max(ans,n-j-1);
        break;
      }
    }
  cout<<ans;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    usingarray(arr,n);
    nospace(arr,n);
  }
  return 0;
}