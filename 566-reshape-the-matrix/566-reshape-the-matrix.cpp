class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int> (c));
        
        // If number of elements of original matrix is not equal toh r x c 
        if(mat.size() * mat[0].size() != r * c)
            return mat;
        
        int row = 0, col = 0;
        
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[i].size(); j++)
            {
                ans[row][col] = mat[i][j];
                col++;
                
                // After one row is completed
                if(col == c)
                {
                    row++;
                    col = 0;
                }
            }
        }
        
        return ans;     
    }
};