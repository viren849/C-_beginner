  
//coin  change problem
//Two Variation in which one is to find min coin and 
//other is all the way.....

//for min-coin..

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int min_coin(vector<int>&coins,int amt)
{
       if(amt == 0)
          return 0;

      int ans=INT_MAX;

      for(int coin:coins)
          {
            if(amt-coin >=0)
                ans=min(ans+0LL,min_coin(coins,amt-coin)+1LL);
          }
          return ans;
}

//in the below code duplicate will be counted eg:
// 1 1 1 2
//1 2 1 1  ,   1 1 2 1,  these all are one but will be counted as 3 this approach
// is wrong then.....

int all_way_coin(vector<int>&coins,int amt)
{
    if(amt==0)return 1;
    if(amt<0)return 0;
    int ans=0;
    for(int coin:coins)
      if(amt-coin>=0)
         ans=ans+all_way_coin(coins,amt-coin);
    return ans;
}

//then the new index concept will come...

int all_way_coin2(int index,vector<int>&coins,int amt)
{
    if(amt==0)return 1;

    if(amt<0)return 0;

    int ans=0;

  for(int i=index;i<coins.size();i++)
      if(amt-coins[i]>=0)
         ans=ans+all_way_coin2(i,coins,amt-coins[i]);
    return ans;
}

//we can take repeatedly.......

int all_way_coin3(int i,vector<int>&coins,int amt)
{
        if(amt == 0)return 1;

        int l=0,r=0;

        if(amt-coins[i] >=0)
        l=all_way_coin3(i,coins,amt-coins[i]);

      if(i+1<coins.size())
        r=all_way_coin3(i+1,coins,amt);
      return l+r;
}
int main()
{
  int n;
  cin>>n;
  vector<int>coins(n);

  for(int i=0;i<n;i++)
     cin>>coins[i];
   int amt;
   cin >> amt;

   cout<<all_way_coin3(0,coins,amt);
}