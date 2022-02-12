//Remove duplicates from the array 
//using two pointers....
//one will keep track of unique element while the other 
//will be at cur index...
#include<iostream>
using namespace std;
int main()
{
  int n;
  
   cin>>n;
   int arr[n];
   for (int i = 0; i < n; ++i)
   {
       cin >> arr[i];
   }

   int cur=0,j=1;
   //i will keep track of unique element..
     for (int i = 1; i < n; ++i)
     {
          if( arr[cur]!=arr[i])
              arr[cur+1]=arr[i],cur++;
          
     }
     for (int i = 0; i <  n; ++i)
     {
       cout <<arr[i]<<" ";
     }
}