
//290. Word Pattern

class Solution {
public:
    bool static isequal(string &temp,string &s)
    {
         int n=temp.size();
        int z=s.size();
        if(n!=z)return 0;
        for(int i=0;i<n;i++)
            if(s[i]!=temp[i])
                return false;
        return true;
        
    }
    bool wordPattern(string pattern, string s) {
        
        int p=pattern.length();
        int n=1;
        for(char c:s)
           if(c==' ') n++; 
        if(n!=p) return false;
        
        unordered_map<char,string>mp;
        unordered_map<string,bool>wd;
        
        stringstream str(s);
        string word;
        int i=0;
        while(str >> word )
        {
            if(mp.find(pattern[i]) == mp.end())
            {
                if(wd[word] == 1) return false;
                mp[pattern[i]]=word;
                wd[word]=1;
            }
            else
            {
                string temp=mp[pattern[i]];
               // cout<<temp<<" "<<word<<" ";
                if(isequal(temp,word) == 0) return false;
            }
            i++;
        }
        return 1;
    }
};