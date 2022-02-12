#include<iostream>
using namespace std;
#include<stack>
//delete middle element of the stack...
void del(stack<int>&st,int k)
{
  if(st.size()==k)
  {
    st.pop();
    return ;
  }
  int temp=st.top();
  st.pop();
  del(st,k);
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
  int k=n/2 + 1;
  del(st,k);

  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }  
  return 0;
}