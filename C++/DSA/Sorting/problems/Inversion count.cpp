//count inversion in an array......
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int merge(int arr[],int lf,int mid,int rt,vector<int>&temp)
{
    int i,j,k;
    i=lf;
    j=mid;
    k=lf;
    int inv=0;

    while((i<=mid-1) and (j<=rt))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv+=(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];

    while(j<=rt)
        temp[k++]=arr[j++];

    for(int i=lf;i<=rt;i++)
        arr[i]=temp[i];

return inv;
}
int mergesort(int arr[],int lf,int rt,vector<int> &temp)
{
    int inv=0;
     if(rt>lf)
     {
        int mid=(lf+rt)/2;
        inv+=mergesort(arr,lf,mid,temp);
        inv+=mergesort(arr,mid+1,rt,temp);

        inv+=merge(arr,lf,mid+1,rt,temp);
     }

     return inv;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];

  vector<int>temp(n);
 cout<<mergesort(arr,0,n-1,temp);

   return 0;
}