  //permutation in a string
#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
#define ll long long 


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int k=s1.length();
          
        vector<int>v(26,0);
        vector<int>g(26,0);
        int l=0,r=0;
        int n=s2.size();
        for(char c:s1)
            v[c-'a']++;
        while(r<n)
        {
            g[s2[r]-'a']++;
            if(r-l+1<k)
                r++;
            else if(r-l+1 == k)
            {
                if(g==v)
            return 1;
                g[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        
         return 0;
    }
};