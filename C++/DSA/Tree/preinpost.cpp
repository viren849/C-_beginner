#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
void preinpost(Node* root)
{
    stack<pair<Node*,int>>st;
    vector<int>pre,in,post;
    st.push({root,1});
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
           pre.push_back(it.first->val);
           it.second++;
           st.push(it);
           if(it.first->left)
            st.push(it->first->left,1);
        }
        else if(it.second==1)
        {  
            in.push_back(it.first-val);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push(it.first->right,1);
         }
            else 
                post.push_back(it.first.val);
    }
}