

//super ugly number .....

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
using namespace std;

 
int main()
{
  
  int n;
  cin >> n;
  
  int s;
  cin>>s;
  vector<int>primes(s);

  for(int i=0;i<s;i++)
    cin >> primes[i];

  int si=primes.size();
  int pi[si]={0};
  int ugly[n+1];
   ugly[0]=1;

   for(int j=1;j<n;j++)
   {
    int mn=INT_MAX;
       for(int i=0;i<si;i++)
        mn=min(primes[i]*ugly[pi[i]],mn);

      ugly[j]=mn;

      for(int i=0;i<si;i++)
      {
        if(ugly[j] % primes[i] == 0) pi[i]++;
      }
   }

   for(int i=0;i<n;i++)
    cout<<ugly[i]<<" ";

  return 0;
}