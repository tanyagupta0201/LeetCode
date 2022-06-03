class NumMatrix {
public:
    // Calculate the prefix sum - row wise and col wise
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        
        // Prefix sum row wise
        for(int i = 0; i < r; i++)
        {
            for(int j = 1; j < c; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        // Prefix sum col wise
        for(int i = 1; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        
        sum = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int total = sum[row2][col2];
        
        int extraSum = (col1 != 0 ? sum[row2][col1 - 1] : 0) + (row1 != 0 ? sum[row1 - 1][col2] : 0) 
                       - ((row1 != 0 && col1 != 0) ? sum[row1 - 1][col1 - 1] : 0);
        
        return total - extraSum;        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */