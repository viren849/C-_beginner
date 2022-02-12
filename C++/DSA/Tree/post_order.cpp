#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
void post(Node* root)
{
	if(root==NULL)return;
	post(root->left);
	post(root->right);
	cout<<root->val;
}
//using 2 stack...
void post(Node* root)
{
	stack<Node*>st1,st2;
	st1.push(root);
	while(!st1.empty())
	{
		auto it=st1.top();
		st1.pop();
		st2.push(it);
		if(it->left)
			st1.push(it->left);
		if(it->right)
			st1.push(it->right);
	}
}
//using 1 stack..
void post(Node* root)
{
    stack<Node*>st;
    vector<int>ans;
    Node *curr=root;
    while(curr!=NULL or !st.empty())
    {
    	if(curr)
    	{
    		st.push(curr);
    		curr=curr->left;
    	}
    	else
    	{
    		Node *temp=st.top()->right;
    		if(temp==NUL)
    		{
                temp=st.top();
                st.pop();
                ans.push(temp->val);
                while(!st.empty() and temp==st.top()->right);
                {
                temp=st.top();
                st.pop();
                ans.push(temp->val);	
                }
    		}
    		else
    			curr=temp;
    	}
    }
}
