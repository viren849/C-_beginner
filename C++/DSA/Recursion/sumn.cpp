#include<iostream>
using namespace std;

//sum of natural no.


//parameterised
int sum(int i,int s)
{
  if(i<1)
  return s;
 sum(i-1,s+i);
}

//functinal
int sum1(int i)
{
  if(i<1)
  return 0;
 return i+sum1(i-1);
}

int main()
{
  int n;
  cin>>n;
  cout<<sum1(n);
}