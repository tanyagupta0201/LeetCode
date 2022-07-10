// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/476388/4-ways-or-Step-by-step-from-Recursion-greater-top-down-DP-greater-bottom-up-DP-greater-fine-tuning
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
	    int dp[n];
        
	    for (int i = 0; i < n; i++)
        {
		    if (i < 2) 
                dp[i] = cost[i];
	    	else 
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
	    }
	
        return min(dp[n - 1], dp[n - 2]);
    }
};