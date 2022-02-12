#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
//check balanced bt
int func(Node* root)
{
    if(!root)
        return 0;
    int lh=func(root->left);
    if(lh==-1)return -1;

    int rh=func(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;

    return 1+max(lh,rh);

}