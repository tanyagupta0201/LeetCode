// https://youtu.be/rscLHdeMKXw

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(); // ease -> 4
        int n = word2.size(); // peace -> 5
        
        
        // rows -> 4 + 1 = 5, cols -> 5 + 1 = 6
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return m - dp[m][n] + n - dp[m][n];        
    }
};