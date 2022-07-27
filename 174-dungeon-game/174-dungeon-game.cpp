class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // if we come out of the grid simply return a large value
        if(i >= m || j >= n)
            return INT_MAX;
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        // calucate health by the 2 possible ways
        int down = solve(i + 1, j, m, n, grid, dp);
        int right = solve(i, j + 1, m, n, grid, dp);
        
        int health = min(down, right);
        
        // we reach the destination when both the sides return INT_MAX
        if(health == INT_MAX)
        {
            health = 1; // both are +ve large integers so min health required = 1
        }
        
        int ans = 0;
        if(health - grid[i][j] > 0)
        {
            ans = health - grid[i][j];
        }
        else
        {
            ans = 1;
        }
             
        return dp[i][j] = ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, INT_MAX));
        
        return solve(0, 0, m, n, dungeon, dp);
    }
};