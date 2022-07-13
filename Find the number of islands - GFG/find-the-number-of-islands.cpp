// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>> &grid, int i, int j, int r, int c)
    {
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != '1')
            return;
            
        // mark the curr land as visited
        grid[i][j] = '2';
        
        // Check in all 8 directions
        dfs(grid, i + 1, j, r, c); 
        dfs(grid, i, j + 1, r, c); 
        dfs(grid, i - 1, j, r, c);
        dfs(grid, i, j - 1, r, c); 
        dfs(grid, i + 1, j + 1, r, c); 
        dfs(grid, i - 1, j + 1, r, c); 
        dfs(grid, i - 1, j - 1, r, c);
        dfs(grid, i + 1, j - 1, r, c); 
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        if(grid.size() == 0)
           return 0;
           
        int r = grid.size(), c = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends