#include<bits/stdc++.h>
using namespace std;
 
//generating all sub array ....
//brute force for loop ...
void printSubstrings(string &str)
{
 
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            cout << subStr << endl;
        }
    }
}
 
void subforlop(string &str)
{
     int n=str.length();

    
     for(int i=0;i<n;i++)
     {
      for(int j=i;j<n;j++)
        {
          for(int k=i;k<=j;k++)
              cout<<str[k];
            cout<<endl;
        }
     }
}
int main() {
    string str;
    int k;
    cin >> str ;
    subforlop(str);
}