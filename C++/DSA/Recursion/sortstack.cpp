#include<iostream>
using namespace std;
#include<stack>
//sorting stack using recursion.......
void insert(stack<int>&st,int temp)
{
   if(st.size()==0||st.top()>=temp)
    {
      st.push(temp);
      return;
    }
    int t=st.top();
    st.pop();
    insert(st,temp);
    st.push(t);
}
void sort(stack<int>&st)
{
     if(st.size()==1)
      return;
    int temp=st.top();
    st.pop();
    sort(st);
   insert(st,temp);
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

    sort(st);

  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }  
  return 0;
}