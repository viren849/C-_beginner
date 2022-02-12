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
vector<vector<int> levelordertraversal(node root)
{
   vector<vector<int>>ans;
   if(root==NULL)return ans;

   queue<node*>q;
   q.push(root);

   while(!q.empty())
   {
   	
   	 vector<int>tmp; 
   	  int s=q.size();
   	  for(int i=0;i<s;i++)
   	  {
     	node* n_root=q.front();
   	  	q.pop();
        tmp.push_back(n_root->val);

   	  	if(!n_root->left) q.push(n_root->left);
   	  	if(!n_root->right)q.push(n_root->right);

   	  }
   	  ans.push_back(tmp);
   }
   return ans;
}