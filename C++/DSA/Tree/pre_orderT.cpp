#include<bits/stdc++.h>
using namespace std;
struct node{

	int val;
	node *left;
	node *right;
};
int main()
{
	
}
void pre_order(node *root)   //root l r
{
	if(root==NULL)return;
	cout<<root->val;
	pre_order(root->left);
	pre_order(root->right);
}

vector<int> iterative_pre(node *root)
{
	vector<int>ans;
	if(root==NULL)return ans;
	stack<node*>st;
	st.push(root);
	while(!st.empty())
	{
		node n_root=st.top();
		st.pop();
		ans.push_back(n_root->val);
		if(n_root->right)st.push_back(n_root->right);
		if(n_root->left)st.push_back(n_root->left);
	}
	return ans;
}