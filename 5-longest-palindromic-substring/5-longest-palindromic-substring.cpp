// https://youtu.be/fxwvVnBMN6I

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        string ans = "";
        int maxLen = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int diff = 0; diff < n; diff++)
        {
            for(int i = 0, j = i + diff; j < n; j++, i++)
            {
                if(i == j)
                {
                    dp[i][j] = 1;
                }
                else if(diff == 1)
                {
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0; // we are adding 2 characters
                }
                else
                {
                    if(s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                
                // compute the palindrome for future use
                if(dp[i][j] != 0)
                {
                    if(j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        ans = s.substr(i, maxLen);
                    }
                }
            }
        }
        return ans;
    }
};