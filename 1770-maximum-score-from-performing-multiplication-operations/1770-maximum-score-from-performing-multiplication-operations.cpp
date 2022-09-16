class Solution {
public:
    int f(int i, int left, int right, vector<int> &nums, vector<int> &mul, vector<vector<int>> &dp)
    {
        if(i == mul.size())
            return 0;
        
        if(dp[i][left] != INT_MIN)
            return dp[i][left];
        
        int l = mul[i] * nums[left] + f(i + 1, left + 1, right, nums, mul, dp);
        int r = mul[i] * nums[right] + f(i + 1, left, right - 1, nums, mul, dp);
        
        return dp[i][left] = max(l, r);        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int n = nums.size();
        int m = multipliers.size();
        int left = 0, right = n - 1;
        
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, INT_MIN));
        return f(0, left, right, nums, multipliers, dp);        
    }
};