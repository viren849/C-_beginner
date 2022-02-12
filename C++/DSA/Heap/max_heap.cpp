#include<bits/stdc++.h>
using namespace std;
//heap...........
void max_heapify(int arr[],int i,int n)
{
     int c1=2*i+1;
     int c2=2*i+2;
     int max=i;
     if(c1<n and arr[c1]>arr[i])
        max=c1;
    if(c2<n and arr[c2]>max)
        max=c2;
    
    if(max!=i){
    swap(arr[i],arr[max]);
    max_heapify(arr,max,n);
      }
}
void buildheap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        max_heapify(arr,i,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    buildheap(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;            
}