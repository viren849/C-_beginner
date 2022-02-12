#include<bits/stdc++.h>
using namespace std;
 
int solution(string &str, int k) {
    int l=0,r=0;
    int n=str.length();
    unordered_map<char,int>mp;
     int ans=0;
    while(r<n)
    {
           mp[str[r]]++;

           
         if(mp.size() > k)
           {    
                while(mp.size() > k)
                  {
                    mp[str[l]]--;
                    if(mp[str[l]] == 0)
                        mp.erase(str[l]);
                     l++;
                  }
           }

           if(mp.size()<=k)
            ans+=(r-l+1);
        r++;
    }
    return ans;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
    cout << solution(str,k);
}