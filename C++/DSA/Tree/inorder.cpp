#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
void inorder(Node* root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->val;
	inorder(root->right);
}
void inorder(Node* root)
{
	vector<int> ans;
	stack<Node*>st;
	Node* curr=root;
	while(true)
	{
		if(curr)
		{   st.push(curr);
            curr=curr->left;
		}
		else
		{
			if(st.empty()) break;
			Node* temp=st.top();
			st.pop();
			 ans.push_back(temp->val);
			 curr=curr->right;
		}
	}
}