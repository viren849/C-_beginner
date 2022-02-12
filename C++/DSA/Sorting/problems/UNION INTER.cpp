//intersection and union of two sorted array....
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int arr[n],arr1[m];

   for(int i=0;i<n;i++)
       cin>>arr[i];
     for(int i=0;i<m;i++)
       cin>>arr1[i];

     vector<int>v(n+m);
     vector<int>v1(n+m);
     
     //...................................................

         //UNION
      int i=0,j=0,k=0;
       if(arr[i]<arr1[j]){
         v[k++]=arr[i++];
       }else v[k++]=arr1[j++];
       while(i<n and j<m)
       {
           if(v[k-1]<arr[i] and arr[i]<arr1[j])
           {
              
                v[k++]=arr[i++];
           }
           else
           if(v[k-1]<arr1[j] and arr1[j]<arr1[i]){
            v[k++]=arr1[j++];
            }
            else if(v[k-1]!=arr[i]){
              v[k++]=arr1[j++];
              i++;
            }
            else {
              i++;j++;
            }
       }
      int z=k;

     //...................................................

         //INTERSECTION
         i=0;j=0,k=0;
         if(arr[i]==arr1[j]){
         v1[k++]=arr[i++];
         j++;
       }
         while(i<n and j<m)
         {
            if(arr[i]==arr1[j] and arr[i]!=v1[k-1]){
              v1[k++]=arr[i];
              i++;j++;
            }
            else if(arr[i]<arr1[j])
              i++;
            else j++;
         }

     //...................................................
     for(int i=0;i<z;i++)
      cout<<v[i]<<" ";
    cout<<endl;
    for(int i=0;i<k;i++)
      cout<<v1[i]<<" ";
    return 0;
}