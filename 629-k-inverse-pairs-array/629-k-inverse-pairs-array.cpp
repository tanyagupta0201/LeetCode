// https://leetcode.com/problems/k-inverse-pairs-array/discuss/846076/C%2B%2B-4-solutions-with-picture

int dp[1001][1001] = { 1 };
class Solution {
public:
    int kInversePairs(int n, int k)
    {
        if (dp[n][k])
            return dp[n][k];
        
        for (int N = 1; N <= n; ++N)
        {
            for (int K = 0; K <= k; ++K) 
            {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
                
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
            }
        }
        
        return dp[n][k];
    }
};