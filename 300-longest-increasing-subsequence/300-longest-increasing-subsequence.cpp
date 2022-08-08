// Explanation: https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!


class Solution
{
public:
    vector<int> dp;
    int lengthOfLIS(vector<int> &nums)
    {
        dp.resize(size(nums) + 1, -1);
        return solve(nums, 0, -1);
    }
    int solve(vector<int> &nums, int i, int prev_i)
    {
        if (i >= size(nums))
            return 0;

        if (dp[prev_i + 1] != -1)
            return dp[prev_i + 1];

        int take = 0;
        int dontTake = solve(nums, i + 1, prev_i);

        if (prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + solve(nums, i + 1, i);

        return dp[prev_i + 1] = max(take, dontTake);
    }
};