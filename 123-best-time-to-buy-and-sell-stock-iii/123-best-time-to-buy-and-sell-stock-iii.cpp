class Solution {
public:
    int f(int idx, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(n == idx)
            return 0;
        
        if(cap == 0)
            return 0;
        
        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        
        int profit = 0;
        
        if(buy == 1)
        {
            // buy or do not buy
            profit = max( -prices[idx] + f(idx + 1, 0, cap, n, prices, dp) , 0 + f(idx + 1, 1, cap, n, prices, dp) );
        }
        else
        {
            // sell or do not sell
            // jab sell karenge tab hi toh capacity par farak padega (sirf ussi case mein decrese hogi)
            profit = max( prices[idx] + f(idx + 1, 1, cap - 1, n, prices, dp) , 0 + f(idx + 1, 0, cap, n, prices, dp) );     
        }
        
        return dp[idx][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy = 1 or 0, capacity = 2 (possible values = 0, 1, 2)
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        
        return f(0, 1, 2, n, prices, dp);
    }
};