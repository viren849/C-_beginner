#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
int depth(Node* root)
{
    if(root==NULL)
        return 0;
    int l=depth(root->left);
    int r=depth(root->right);
    return 1+max(l,r);
}