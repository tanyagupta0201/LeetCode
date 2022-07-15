class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int r, int c)
    {
        int ar = 0;
        
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != 1)
        {
            return 0;
        }
        
        ar++;
        grid[i][j] = 2;
        
        ar += dfs(grid, i + 1, j, r, c);
        ar += dfs(grid, i - 1, j, r, c);
        ar += dfs(grid, i, j + 1, r, c);
        ar += dfs(grid, i, j - 1, r, c);
        
        return ar;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        
        int area = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    area = max(area, dfs(grid, i, j, r, c));
                }
            }
        }
        
        return area;
    }
};