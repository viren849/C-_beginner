#include<iostream>
using namespace std;
#include<vector>
//sort an array using recursion....

void insert(int arr[],int temp,int n)     //  void insert(vector<int>&v,int temp)       
{
  if(n==0 || arr[n-1]<=temp){              //  if(v.size()==0||v[v.size()-1]<=temp){
     arr[n]=temp;                            //       v.push_back(temp);
    return;                                 //        return;
  }

  int t =arr[n-1];                         //  int t=v[v.size()-1];
  n=n-1;                                  //    v.pop_back();
  insert(arr,temp,n);                       //     insert(v,temp);
  arr[n+1]=t;                                 //   v.push_back(t);
}

void sort(int arr[],int n)                   //void sort(vector<int>&v)
{                                      //         {
   
   if(n==1)                                 //    if(v.size()==1)
    return ;                                //       return;
  int temp=arr[n-1];                       //    int temp=v[v.size()-1];
   n=n-1;                                  //    v.pop_back();
 sort(arr,n);                              //    sort(v);
  insert(arr,temp,n);                       //   insert(v,temp);
}                                           //     }

int main()
{
  int n;
  cin>>n;
 int v[n];                           //    vector<int>v(n);

  for(int i=0;i<n;i++)
    cin>>v[i];

  sort(v,n);

  for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
  return 0;
}