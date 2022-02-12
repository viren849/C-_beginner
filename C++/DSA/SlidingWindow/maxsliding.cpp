
//maximum in sliding window..

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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int k;
    cin>>k;

    int l=0,r=0;
    int mx=INT_MIN;
    deque<int>q;
    vector<int>ans;

    
  int i=0;
    while(r<n)
    {
       while(q.size()>0 and q.back()<arr[r])
           q.pop_back();

       q.push_back(arr[r]);

         if(r-l+1 < k)
          r++;
        else if(r-l+1 ==k)
        {
          ans.push_back(q.front());
          if(q.front()==arr[l])
            q.pop_front();
          l++;r++;
        }
    }

    for(int i:ans)
      cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}