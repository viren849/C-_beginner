//121. Best Time to Buy and Sell Stock

//using AUXILARY SPACE O(2n) ~ n

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=prices[0];
        right[n-1]=prices[n-1];
        
        for(int i=1;i<n;i++)
            left[i]=min(left[i-1],prices[i]);
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],prices[i]);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(right[i]-left[i],ans);
        }
        return ans;
    }
};

//using kadane algorithm...
// All the straight forward solution should work, but if the interviewer twists the 
//question slightly by giving the difference array of prices, Ex: for {1, 7, 4, 11}, 
//if he gives {0, 6, -3, 7}, you might end up being confused.

// Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) 
// the original array, and find a contiguous subarray giving maximum profit. 
//If the difference falls below 0, reset it to zero.

    public int maxProfit(int[] prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
