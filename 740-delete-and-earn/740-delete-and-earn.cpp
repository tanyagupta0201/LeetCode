// https://youtu.be/ZFKRSzbEHnM

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        // Find the max element
        int maxi = *max_element(nums.begin(), nums.end());
        
        int dp[20004];
        vector<int> freq(20004); // stores the freq of each number
        
        for(auto it: nums)
        {
            freq[it]++;
        }
        
        dp[1] = freq[1];
        dp[2] = max(dp[1], 2 * freq[2]);
        
        for(int i = 3; i <= maxi; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
        }
        
        return dp[maxi];
    }
};