//Russian Peasant Method
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int Peasant(int a ,int b)
{
	if(b==0)return 0;

	  if(b&1)return Peasant(a<<1,b>>1)+a;
    else  return Peasant(a<<1,b>>1);
}
int main()
{
	int a,b;
	cin>>a>>b;
  
   int sol=0;
   cout<<Peasant(a,b)<<endl;
	while(b)
      {

      	if(b&1)sol+=a;
      	a<<=1;
      
      	b>>=1;	
      }
      cout<<sol;
}