/*
    The answer will be a recursive sequence as follow: 1, 1, 2, 5, 11, 24, 53, 117, 258, 569, 1255
    It grows at a speed about 2 times bigger each time.
    If you write down this recursive sequence and do some calculations, you may find that:

    5 = 2 * 2 + 1
    11 = 5 * 2 + 1
    24 = 11 * 2 + 2
    53 = 24 * 2 + 5
    117 = 53 * 2 + 11
    A[N] = A[N-1] * 2 + A[N-3]

*/

// Recursive
class Solution
{
public:
    long mod = 1e9 + 7;

    int solve(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];

        dp[n] = (2 * solve(n - 1, dp) % mod + solve(n - 3, dp) % mod) % mod;

        return dp[n];
    }

    int numTilings(int n)
    {
        vector<int> dp(1001, -1);

        dp[0] = 1, dp[1] = 1, dp[2] = 2;

        return solve(n, dp);
    }
};