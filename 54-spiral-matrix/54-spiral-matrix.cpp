class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> arr;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row_start = 0, row_end = rows - 1,
            col_start = 0, col_end = cols - 1;
        
        while (row_start <= row_end && col_start <= col_end) 
        {
			// going RIGHT
            for (int j = col_start; j <= col_end; j++)
            {
                arr.push_back(matrix[row_start][j]);
            }
            row_start++;
            
			// going DOWN
            for (int i = row_start; i <= row_end; i++) 
            {
                arr.push_back(matrix[i][col_end]);
            }
            col_end--;
            
			// going LEFT
            if (row_start <= row_end) 
            {
                for (int j = col_end; j >= col_start; j--) 
                {
                    arr.push_back(matrix[row_end][j]);
                }
                row_end--;
            }
            
			// going UP
            if (col_start <= col_end) 
            {
                for (int i = row_end; i >= row_start; i--)
                {
                    arr.push_back(matrix[i][col_start]);
                }
                col_start++;
            }
        }
        
        return arr;
    }
};
