//TEAM.....
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<algorithm>
int main()
{  
   int t;
   cin>>t;
   int c=0;
   while(t--)
   {
      int arr[2]={0};
      int x,y,z;
     cin>>x>>y>>z;
       arr[x]++;
       arr[y]++;
       arr[z]++;
       if(arr[1]>arr[0])
         c++;
   }
   cout<<c<<endl;
}