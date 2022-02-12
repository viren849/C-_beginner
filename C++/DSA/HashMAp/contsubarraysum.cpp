
// Continuous Subarray Sum

// There is a condition of subarray length of atleast 2, thats why we 
// store sum in the map mods after 1 iteration, we store the sum in a variable 
// pretemp.
// We dont need to store the whole sum, we just store sum mod k or sum % k ,
//  as (a + b + .... + z)%k is equivalent to ( a%k + b%k + .... + z%k).

// As we cant divide any number by 0, we store the whole in the 
// array. And also fork = 0 , the function will return true if there are two
//  continous 0 ( i.e [1, 4, 5, 0, 0, 8] ) in the given array.
https://leetcode.com/problems/continuous-subarray-sum/discuss/1101690/C%2B%2B-code-with-20ms-runtime-and-picture-explanation

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
     unordered_map<int,int>mp;
        
        int r=0;
        int pretemp=0;
        while(r<n)
        {
            sum=(sum+nums[r])%k;
            if(mp[sum])return true;
             mp[pretemp]++;
            pretemp=sum;
            r++;
        }
        return 0;
    }
};