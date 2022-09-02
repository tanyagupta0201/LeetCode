class Solution {
public:
    int count(int n, int m, string s, string t, vector<vector<int>> &dp)
    {
        // if str2 is exhausted then we have got a subsequence
        if(m == 0)
            return 1;
        
        // if str1 is exhausted and str1 is not exhausted then we cannot get any subsequence
        if(n == 0)
            return 0;
        
        // if the length of str1 becomes less than length of str2, then we cant have any subsequence
        if(n < m)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        // if the character of both the strings matches, then we have 2 ways
        if(s[n - 1] == t[m - 1])
        {
            // we want the curr character of str1 + we dont want the curr character of str1
            return dp[n][m] = count(n - 1, m - 1, s, t, dp) + count(n - 1, m, s, t, dp);
        }
        else
        {
            // decrease the the index of str1 by 1
            return dp[n][m] = count(n - 1, m, s, t, dp);
        }
    }
    
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return count(n, m, s, t, dp);
    }
};