class Solution {
public:
    int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        // case 1: Out of bounds 
        if(j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c -1)
            return -1e8;
        
        // case 2: when robots reach destination ie. the last row
        if(i == r - 1)
        {
            // when both robots reach the same block, so count only once
            if(j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                // when they reach different blocks
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        // Now explore all the paths of both the robots simultaneously
        // For one movement of Robot 1, Robot 2 can have 3 possible movements
        // As Robot 1 has 3 possible movements, There would be total 3 x 3 = 9 total movements
        // the possible values can be {-1, 0, +1}
        
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++)
        {
            for(int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;
                
                if(j1 == j2)
                {
                    value = grid[i][j1] + solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                }
                else
                {
                    value = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                }
                
                maxi = max(value, maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid)
    {
        int r = grid.size(), c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        
        return solve(0, 0, c - 1, r, c, grid, dp);        
    }
};