class Solution {
public:
    bool subsetSum(vector<int> nums, int n, int s)
    {
        int dp[n + 1][s + 1];
        
        for(int i = 0; i < s + 1; i++)
        {
            dp[0][i] = false;
        }
        
        for(int i = 0; i < n + 1; i++)
        {
            dp[i][0] = true;
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < s + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    // Include or do not include
                    dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
                }
                else
                {
                    // Do not include
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][s];
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        // if sum is odd, 2 equal partition can never be made
        if(sum % 2 != 0)
        {
            return false;
        }
        else
        {
            // Just find if one subset exists whose sum is equal to target, if it exists then the second one will definately exist 
            return subsetSum(nums, n, sum / 2);
        }
    }
};