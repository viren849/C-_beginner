
//koko eating banana

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 
 //bruteforce..
 int minEatingSpeed(vector<int>& piles, int h) {
       
        int ans=1;
       while(true)
       {
           int hs=0;
        for(int pile : piles)
        {
            hs+=pile/ans + (pile % ans !=0);
             
                if(hs > h)
                    break;
        }
           if(hs<=h)return ans;
           ans++;
       }
        return ans;
   
    }


// binary search 

    int mineat(int k,int arr[],int n)
    {
      int sum=0;
         for(int i=0;i<n;i++)
         {
               sum+=arr[i]/k+(arr[i] % k !=0);
             //  cout<<sum<<" ";
         }
         return sum;
    }
int main(){

  int n;
  cin>>n;
  int arr[n];
  int mx=INT_MIN;

  for(int i=0;i<n;i++)
   {
    cin>>arr[i];
    mx=max(mx,arr[i]);
  }


  int h;
  
  cin>>h;

  int lo=1,hi=mx;
  while(lo<hi)
  {
     int mid=lo+(hi-lo)/2;
     
     int x=mineat(mid,arr,n);
     if(x <= h)
       hi=mid;
     else  
        lo=mid+1;
     // break;
  }
  
  cout<<lo<<" " <<hi;
  return 0;
}