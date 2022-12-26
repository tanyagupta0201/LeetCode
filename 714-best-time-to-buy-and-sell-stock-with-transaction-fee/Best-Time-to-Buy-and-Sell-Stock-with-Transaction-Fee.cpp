// after every transaction you need subtract fees
// either subtract it while buying or while selling, other code remains same

class Solution
{
public:
    int f(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp, int fee)
    {
        if (idx == n)
            return 0;

        int profit = 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy == 1)
        {
            // 2 choices - want to buy  OR not want to buy
            // buying gives -ve profit
            profit = max(-prices[idx] - fee + f(idx + 1, 0, n, prices, dp, fee), 0 + f(idx + 1, 1, n, prices, dp, fee));
        }
        else
        {
            // 2 choices - want to sell OR not want to sell
            // Selling gives +ve profit
            profit = max(prices[idx] + f(idx + 1, 1, n, prices, dp, fee), 0 + f(idx + 1, 0, n, prices, dp, fee));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        // idx -> 0 to (n - 1), buy -> 0 or 1
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, n, prices, dp, fee);
    }
};