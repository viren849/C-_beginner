#include<bits/stdc++.h>
using namespace std;
int partion(int arr[],int st,int end)
{
    int pivot=arr[end];
    int k=st;
    for(int i=st;i<end;i++)
    {
        if(arr[i]<=pivot){
           swap(arr[i],arr[k]);
           k++;
        }
    }
    swap(arr[k],arr[end]);
    return k;
}
int randompartion(int arr[],int st,int end)
{
       srand(time(NULL));
       int ind=st+rand()%(end-st);
       swap(arr[ind],arr[end]);
       return partion(arr,st,end);
}
void quicksort(int arr[],int st,int end)
{
    if(st<end)
    {
        int pivot=randompartion(arr,st,end);
        quicksort(arr,st,pivot);
        quicksort(arr,pivot+1,end);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;            
}