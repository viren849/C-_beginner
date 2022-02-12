
//hello 2022 1
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
    int n,k;
    cin>>n>>k;
    if(k<=(n+1)/2)
    {
  
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
          if(j==i and  k>0 and i%2==0){
            cout<<"R";
            k--;
          }
          else cout<<".";
          cout<<endl;
      }
    } 
    else cout<<-1<<endl;
  }
  return 0;
}