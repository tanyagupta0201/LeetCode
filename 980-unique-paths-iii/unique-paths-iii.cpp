// TC = O(4 ^ N)
// SC = O(N) - Stack space

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int x, int y, int zero)
    {
        // check out of bound case
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
        {
            return 0; // there is no path
        }

        // when you reach the last position
        if (grid[x][y] == 2)
        {
            // check that you have covered all the zeros or not
            // we are checking zero for -1 and not for zero because when we reach the target, we are covering one more cell
            if (zero == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // mark visited cell as visited
        grid[x][y] = -1;

        // decrease the count of zero
        zero--;

        int totalPaths = dfs(grid, x, y - 1, zero) +
                         dfs(grid, x + 1, y, zero) +
                         dfs(grid, x, y + 1, zero) +
                         dfs(grid, x - 1, y, zero);

        // if we don't find a path we need to backtrack again
        grid[x][y] = 0;
        zero++;

        return totalPaths;
    }

    // that walk over every non-obstacle square exactly once => means we need to walk over every cell that is zero
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        int zero = 0;
        int start = -1, end = -1;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // count number of zeros
                // because at the end when we reach the destination, we need to check whether we covered all zeros or not
                if (grid[i][j] == 0)
                {
                    zero++;
                }

                // find the starting and the ending point
                if (grid[i][j] == 1)
                {
                    start = i;
                    end = j;
                }
            }
        }

        return dfs(grid, start, end, zero);
    }
};