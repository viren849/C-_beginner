// 134. Gas Station
#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;

  int gas[n],cost[n];

  for(int i=0;i<n;i++)
    cin>>gas[i];
  for(int i=0;i<n;i++)
    cin>>cost[i];

  int total=0;

  for(int i=0;i<n;i++)
  {
     total += gas[i] - cost[i];

  }
  if(total < 0) cout<<-1;
  else
  {
    int tank=0;
    int ans=0;
       for(int i=0;i<n;i++)
       {
          tank+=gas[i]-cost[i];
          if(tank < 0)
          {
            ans=i+1;
            tank = 0 ;
          }
       }
       cout<<ans;
  }
  cout<<endl;
  return  0 ;
}