//Remove ELEMENTS from the array 
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
   int val;
   cin>>val;

   int cur=0,j=1;
   //i will keep track of unique element..
     for (int i = 0; i < n; ++i)
     {
          if( val!=arr[i])
              swap(arr[cur++],arr[i]);
          
     }
     for (int i = 0; i <  n; ++i)
     {
       cout <<arr[i]<<" ";
     }
}