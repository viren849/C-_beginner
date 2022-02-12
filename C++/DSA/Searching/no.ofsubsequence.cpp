
//392. Is Subsequence
class Solution {
public:

    bool twopointer(string s, string t)
    {
         int n=s.length();
        int m=t.length();
        
        if(!n )return 1;
        int i=0,j=0;
        int cnt=n;
        
        while(i<n && j<m)
        { 
              if(s[i] == t[j])
              {
                  cnt--;
                  i++;
              }
              if(cnt == 0)return 1;
              j++;
        }
        return 0;

    }

   // with map+binary search...
    class Solution {
public:
    int binary(int low ,vector<int>&v)
    {
        
          int l=0,r=v.size()-1;
          int ans=-1;
          while(l<=r)
          {
               int mid=l+(r-l)/2;
               if(v[mid]>low)
               {
                   r=mid-1;
                   ans=v[mid];
               }
               else l=mid+1;
          }
          return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>>v(26);

        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'].push_back(i);
        }

          int cnt=0;

          for( string word : words)
          {
               int m=word.length();
               
               int low=-1;
               int flag=1;
              
               for(int i=0;i<m;i++)
               {
                   int ind=word[i]-'a';
                      
                        low= binary(low,v[ind]);
                        if(low == -1)flag=0;
                    
               }
             
             if(flag)cnt++;
           }
        return cnt;
    }
};