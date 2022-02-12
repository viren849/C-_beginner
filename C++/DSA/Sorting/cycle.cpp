#include<bits/stdc++.h>
using namespace std;
//cycle sort
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<n;i++)
        if(v[i]-1!=i)
            swap(v[i],v[v[i]-1]);
                
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";            
    return 0;            
}