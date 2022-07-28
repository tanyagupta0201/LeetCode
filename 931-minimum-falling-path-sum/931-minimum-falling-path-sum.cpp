class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j < 0 || j > matrix[0].size() - 1)
            return INT_MAX;
        
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        long long int right_diagonal = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);
        long long int left_diagonal = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        
        return dp[i][j] = min(up, min(right_diagonal, left_diagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        long long int mini = INT_MAX;
        
        for(int j = 0; j < m; j++)
        {
            mini = min(mini, solve(n - 1, j, matrix, dp));
        }
        
        return mini;
    }
};