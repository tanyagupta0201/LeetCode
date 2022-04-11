/*

It is a observation based question.

If k is 1 then new column is (j + 1) and if k is k then new column is (j + k) and new column should in range [0, m-1]. So new column is (j + k) % m.

For row, we have to first find the number of rows added to previous row which is equal to the number of times (j + k) exceeds m. So, number of rows added is (j + k) / m.

So, new row is (i + (j + k) / m) and new row should in range [0, n-1]. So new column is (i + (j + k) / m) % n.

*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> ans(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                int newJ = (j + k) % col; // (j + numbers of columns added) % m

                int newI = (i + (j + k) / col) % row; // (i + numbers of rows added) % n

                ans[newI][newJ] = grid[i][j];
            }
        }
       
        return ans;
     }
};


