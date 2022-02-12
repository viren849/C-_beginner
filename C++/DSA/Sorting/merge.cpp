#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int st,int mid,int end)
{
    int ls=mid-st+1;
    int rs=end-mid;
    int l[ls],r[rs];

    for(int i=0;i<ls;i++)
        l[i]=v[st+i];
    for(int i=0;i<rs;i++)
        r[i]=v[i+mid+1];
     int i=0,j=0,k=st;

    while(i<ls and j<rs)
        if(l[i]<=r[j])
            v[k++]=l[i++];
        else 
            v[k++]=r[j++];

    while(i<ls)
       v[k++]=l[i++];
   while(j<rs)
        v[k++]=r[j++];
}
void mergesort(vector<int>&v,int st,int end)
{
    if(st<end)
    {
        int mid=(st+end)/2;
           mergesort(v,st,mid);
           mergesort(v,mid+1,end);
           merge(v,st,mid,end);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    mergesort(v,0,n-1);
                
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";            
    return 0;            
}