#include<bits/stdc++.h>
using namespace std;
//heap...........
void min_heapify(int arr[],int i,int n)
{
     int c1=2*i+1;
     int c2=2*i+2;

     int small=i;
     if(c1<n and arr[c1]<arr[i])
        small=c1;
    if(c2<n and arr[c2]<arr[small])
        small=c2;
    if(small!=i){
    swap(arr[i],arr[small]);
    min_heapify(arr,small,n);
      }
}
void buildheap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        min_heapify(arr,i,n);
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