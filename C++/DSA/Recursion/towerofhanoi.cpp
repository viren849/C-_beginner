#include<iostream>
using namespace std;
void toh(int n,char from,char to,char hlp)
{
  if(n==0)
    return;
  toh(n-1,from,hlp,to);
  cout<<n<<" "<<from<<"-->"<<to<<" "<<hlp<<endl;
  toh(n-1,hlp,to,from);
    
}
int main()
{

  int n;
  cin>>n;
  toh(n,'A','B','H');
  return 0;
}