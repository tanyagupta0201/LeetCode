// https://youtu.be/mBZEFR3LSNs
class Solution
{
public:
    int dp[301][11];

    int solve(vector<int> &jobDifficulty, int n, int i, int d)
    {
        // in this case all the tasks have to be done in a single day
        // answer would be max element
        if (d == 1)
        {
            return *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        if (dp[i][d] != -1)
            return dp[i][d];

        int ans = INT_MAX;
        int CurrMaxJob = INT_MIN; // will store max job currently

        for (int j = i; j <= n - d; j++)
        {
            CurrMaxJob = max(CurrMaxJob, jobDifficulty[j]);
            // find the answer for each possible way and then choose minimum among them
            ans = min(ans, CurrMaxJob + solve(jobDifficulty, n, j + 1, d - 1));
        }

        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        memset(dp, -1, sizeof(dp));
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        return solve(jobDifficulty, n, 0, d);
    }
};