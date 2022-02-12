#include<iostream>
using namespace std;
#include<string>

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    string t;//always 3
    cin>>t;

    int arr[26]={0};
    
    for(char c:s )
      arr[c-97]++;

     if(t=="abc" and arr[0]>0 and arr[1]>0 and arr[2]>0)
       {
        while(arr[0]--)  
        cout<<'a';
        while(arr[2]--)
        cout<<'c';
        while(arr[1]--)
          cout<<'b';

        for(int j=3;j<26;j++)
            if(arr[j]>0)
             for(int i=0;i<arr[j];i++)
              cout<<char(j+97);
       }
     else{
           for(int j=0;j<26;j++)
            if(arr[j]>0)
             for(int i=0;i<arr[j];i++)
              cout<<char(j+97);
     }
     cout<<endl;
  }
  return 0;
}