class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Check out of bounds condition
        if(i < 0 || j < 0 || i >= row || j >= col)
            return 0;
        
        // If there is some value in memo matrix that means it has been checked
        if(memo[i][j] > 0)
            return memo[i][j];
        
        int currentMax = 1;
        
        // check if its a helpful neighbour(should help in forming longest increasing path)
        // Down neighbour (i + 1, j)
        if(i + 1 < row && i + 1 >= 0 && matrix[i + 1][j] > matrix[i][j])
        {
            currentMax = max(currentMax, 1 + dfs(matrix, i + 1, j, memo));
        }
        
        // Top neighbour (i - 1, j)
        if(i - 1 < row && i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        {
            currentMax = max(currentMax, 1 + dfs(matrix, i - 1, j, memo));
        }
        
        // Right neighbour (i, j + 1)
        if(j + 1 < col && j + 1 >= 0 && matrix[i][j + 1] > matrix[i][j])
        {
            currentMax = max(currentMax, 1 + dfs(matrix, i, j + 1, memo));
        }
        
        // left neighbour (i, j - 1)
        if(j - 1 < col && j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        {
            currentMax = max(currentMax, 1 + dfs(matrix, i, j - 1, memo));
        }
        
        memo[i][j] = currentMax;
        
        return currentMax;        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Mark every element in the memo matrix as zero
        vector<vector<int>> memo(row, vector<int>(col, 0));
        
        int ans = 0;
        
        // We will traverse each value in the matrix and call dfs to check for its neighbours
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                ans = max(ans, dfs(matrix, i, j, memo)); // dfs finds longest increasing path
            }
        }
        
        return ans;
    }   
};