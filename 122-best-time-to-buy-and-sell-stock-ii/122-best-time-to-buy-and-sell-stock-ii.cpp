class Solution {
public:
    int f(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(idx == n)
            return 0;
        
        int profit = 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        if(buy == 1)
        {
            profit = max( -prices[idx] + f(idx + 1, 0, n, prices, dp), 0 + f(idx + 1, 1, n, prices, dp));   
        }
        else
        {
            profit = max( prices[idx] + f(idx + 1, 1, n, prices, dp), 0 + f(idx + 1, 0, n, prices, dp));   
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy -> 0 or 1
        vector<vector<int>> dp(n, vector<int> (2, -1));
        
        return f(0, 1, n, prices, dp);
    }
};