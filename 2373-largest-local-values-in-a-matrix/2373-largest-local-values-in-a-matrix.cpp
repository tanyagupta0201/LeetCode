class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        // find max of 3x3 grid centred around row i + 1 and column j + 1
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = 1; j <= n - 2; j++)
            {
                int maxi = 0;
                
                maxi = max(maxi, max(grid[i - 1][j - 1], max(grid[i - 1][j], grid[i - 1][j + 1])));
                
                maxi = max(maxi, max(grid[i][j - 1], max(grid[i][j], grid[i][j + 1])));
                
                maxi = max(maxi, max(grid[i + 1][j - 1], max(grid[i + 1][j], grid[i + 1][j + 1])));

                ans[i - 1][j - 1] = maxi;
            }
        }
        
        return ans;
    }
};