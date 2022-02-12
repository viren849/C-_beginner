#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a;
    cin>>a;
    if(a%2==0)
    	cout<<0<<endl;
    else 
    {
    	string s=to_string(a);
    	int k=s.size();
        //cout<<k<<" ";
    	if((s[0]-'0')%2==0)
    		cout<<1<<endl;
    	else {
    		int flag=1;

    		for(int i=1;i<k-1;i++)
    			if((s[i]-'0')%2==0){
    				cout<<2<<endl;
    				flag=0;
    				break;
    			      }

    	  if(flag)
    		cout<<-1<<endl;
    	}
    }
  }
  return 0;
}