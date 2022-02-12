#include<iostream>
using namespace std;
#include<limits.h>
#include<algorithm>
int main()
{  
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    int m;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>m;

    sort(arr,arr+n);
    int min=INT_MAX;
    for(int i=0;i<=n-m;i++)
    {
        int ans = arr[i+m-1]-arr[i];
        if(ans<min)
            min=ans;
    }
    cout<<min<<endl;
}
    return 0;

}