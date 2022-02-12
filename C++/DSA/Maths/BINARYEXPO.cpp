//BINARY EXPO....
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// int Power(int x ,int n)
// {
// 	int ans=1;
//   while(n>0)
//   {
//     if(n&1)ans*=x;

//     x=x*x;

//     n>>=1; 
//   }
//   return ans;
// }
int Power(int base,int n)
{
    if(n==0)return 1;

     int res=Power(base,n>>1);

     if(n&1)
        return res*res*base;
      else 
        return res*res;
}
int main()
{
	int a,b;
	cin>>a>>b;
  
   cout<<Power(a,b)<<endl;
	
}