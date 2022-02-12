//Next greater element ..

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
     
   int n;
   cin>>n;
   int v[n];
     
   for(int i=0;i<n;i++)
     cin>>v[i];

  stack<int>st;

   vector<int>ans(n);

   int i=2*n-1;
   
   while(i >=0)
   {   
       int t=i%n;
       while( !st.empty() && v[t]>=st.top())
          st.pop();
        if(st.empty())ans[t]=-1;
        else
             ans[t]=st.top(); 
       st.push(v[t]);
       i--;
   }
   
   for(auto it : ans)
    cout<<it<<" ";
  return 0;
}