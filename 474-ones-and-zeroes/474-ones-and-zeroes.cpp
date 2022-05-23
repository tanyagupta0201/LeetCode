class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        // Bottom Up Approach
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1)));
        
        for(int i = 1; i <= strs.size(); i++)
        {
            int countZero = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int countOne = strs[i - 1].size() - countZero;
            
            for(int j = 0; j <= m; j++)
            {
                for(int k = 0; k <= n; k++)
                {
                    // Two choices - take or do not take
                    if(j - countZero >= 0 && k - countOne >= 0)
                    {
                        dp[i][j][k] = max(1 + dp[i - 1][j - countZero][k - countOne], dp[i - 1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        
        return dp[strs.size()][m][n];
    }
};