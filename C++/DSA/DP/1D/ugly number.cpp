
//ugly number ... (2,3,5)

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
using namespace std;

void using dp()
{
   int ugly[n];
  ugly[0] = 1;

  int i2 = 0;
  int i3 = 0;
  int i5 = 0;
  int i=1;
  while(i < n){

  ugly[i] = min( ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
   
   if(ugly[i] % 2 == 0) i2++;
   if(ugly[i] % 3 == 0) i3++;
   if(ugly[i] % 5 == 0) i5++;
   i++;
}

}
int divide(int a,int b)
{
  while(a%b == 0)
    a = a/b;
  return a;
}
bool isugly(int n)
{
   int no=n;

   no=divide(no,2);
   no=divide(no,3);
   no=divide(no,5);

   return no == 1;
}
int main()
{
  
  int n;
  cin >> n;

  int count = 1 ;
  int i = 2;
  
  while(count < n)
  {
    if(isugly(i))
     { 
      count++;
       cout<<i<<" ";
     }
    i++;
  }
  return 0;
}