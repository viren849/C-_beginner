#include<iostream>
using namespace std;
#include<stack>
//Reverse a stack using recursion.....

void reverse(stack<int>&st)
{
      if(st.size()==1)
        return ;
      int temp=st.top();
      st.pop();
      reverse(st);
      st.push(temp);
}
int main()
{
  int n;
  cin>>n;                         
 stack<int> st;

  for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      st.push(x);
    }
  
  reverse(st,k);

  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }  
  return 0;
}