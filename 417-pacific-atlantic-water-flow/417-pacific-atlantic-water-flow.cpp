class Solution {
public:
    void dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &ocean)
    {
        // we are checking from the reverse direction 
        
        // Out of bound case
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return;
        
        // if already visited simply return
        if (ocean[i][j] == 1)
            return;
        
        // value must be greater or equal to curr value
        // this is invalid case
        if (matrix[i][j] < prev)
            return;

        // mark visited
        ocean[i][j] = 1;
        
        // call dfs in all 4 directions
        dfs(matrix, i + 1, j, matrix[i][j], ocean);
        dfs(matrix, i - 1, j, matrix[i][j], ocean);
        dfs(matrix, i, j + 1, matrix[i][j], ocean);
        dfs(matrix, i, j - 1, matrix[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> ans;
        
        if (matrix.size() < 1)
            return ans;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        // We will visit all the elements of the matrix from all the 4 sides
        // for this we will make 2 matrices
        // one for pacific ocean and another for atlantic ocean
        // the intersection of both the matrices where both the matrices cell has 1 will be the cordinates in the final ans
        vector<vector<int>> pacific(r, vector<int>(c, 0));
        vector<vector<int>> atlantic(r, vector<int>(c, 0));

        for (int col = 0; col < c; col++)
        {
            dfs(matrix, 0, col, INT_MIN, pacific);
            dfs(matrix, r - 1, col, INT_MIN, atlantic);
        }

        for (int row = 0; row < r; row++)
        {
            dfs(matrix, row, 0, INT_MIN, pacific);
            dfs(matrix, row, c - 1, INT_MIN, atlantic);
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    vector<int> v(2);
                    
                    v[0] = i;
                    v[1] = j;
                    
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};