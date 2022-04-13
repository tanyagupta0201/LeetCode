class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int row_start = 0, row_end = n - 1,
            col_start = 0, col_end = n - 1;
        
        int val = 1;
        
        while (row_start <= row_end && col_start <= col_end) 
        {
			// going RIGHT
            for (int j = col_start; j <= col_end; j++)
            {
                matrix[row_start][j] = val++;
            }
            row_start++;
            
			// going DOWN
            for (int i = row_start; i <= row_end; i++) 
            {
                matrix[i][col_end] = val++;
            }
            col_end--;
            
			// going LEFT
            if (row_start <= row_end) 
            {
                for (int j = col_end; j >= col_start; j--) 
                {
                    matrix[row_end][j] = val++;
                }
                row_end--;
            }
            
			// going UP
            if (col_start <= col_end) 
            {
                for (int i = row_end; i >= row_start; i--)
                {
                    matrix[i][col_start] = val++;
                }
                col_start++;
            }
        }
        
        return matrix;
    }
};