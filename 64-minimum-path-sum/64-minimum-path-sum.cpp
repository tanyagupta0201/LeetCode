// Memoization

class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &grid, vector<vector<long long int>> &dp)
    {
        if(i == 0 && j == 0)
            return grid[0][0];
        
        if(i < 0 || j < 0)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long int up = grid[i][j] + solve(i - 1, j, grid, dp);
        long long int left = grid[i][j] + solve(i, j - 1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long int>> dp(m, vector<long long int> (n, -1));
        
        return solve(m - 1, n - 1, grid, dp);
    }
};