// Minimum Operations to Reduce X to Zero

//observation ......maximize the subarray such that remsining element automatically
//minimize.....

//let a1,a2,a3,a4,a5,a6,a7,a8           and   
//let X=a1+a2+a7+a8

//if Total sum of array - X =  longest subarray then the problem will be s
//solved automatically........


//using hashmap........
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=0;

        for(int i:nums)s+=i;
          
          s-=x;
          if(s==0)return n;
          unordered_map<int,int>mp;

          int len=INT_MIN;

          int tmpsum=0;
        for(int i=0;i<n;i++)
        {
              tmpsum+=nums[i];
            
            if(tmpsum == s)
                len=i+1;
            
              if(mp.find(tmpsum-s)!=mp.end())
                len=max(len,i-mp[tmpsum-s]);
            
                 mp[tmpsum]=i;
        }
       
        return len==INT_MIN?-1:n-len; 
    }
};
//using sliding window.........
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=0;

        for(int i:nums)s+=i;
          
          s-=x;
        
          if(s==0)return n;
          if(s<0)return -1;

          int len=INT_MIN;

          int tmpsum=0;
           int l=0,r=0;
        
        while(r<n)
        {
            tmpsum+=nums[r];
            
              while(tmpsum > s)
              {
                  tmpsum-=nums[l];
                  l++;
              }
                if(tmpsum == s)
                len=max(len,r-l+1);
            r++;
        }
       
        return len==INT_MIN?-1:n-len; 
    }
};