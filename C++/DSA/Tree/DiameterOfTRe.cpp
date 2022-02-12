#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
int lenght=0;
int diametr(Node* root)
{
    if(!root)
        return 0;
    int lh=diametr(root->left);
    int rh=diametr(root->right);
    lenght=max(lenght,lh+rh);
    return max(lh+rh)+1;
}
cout<<lenght;