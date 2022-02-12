  
// Minimum Size Subarray Sum

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 

 
int main()
{
    int n;
    cin>>n;
    vector<int>arr;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int k;
    cin >> k;

    int l=0,r=0;
    int sum=0,len;
    int mn=INT_MAX;

    while(r<n)
    {
      sum+=arr[r];
        while(sum>=k)
        {
           mn=min(mn,r-l+1);
          sum-=arr[l++];
         
        }

      r++;
    }
   cout<<mn<<endl;
   return 0;
}