class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i] + mat[i][n - i - 1]; // sum += left Diagonal + right diagonal
        }

        // if matrix is even, no value is being repeated in both the diagonals
        if (n % 2 == 0)
            return sum;

        // in case of odd subtract the middle value that was common in both the matrix
        return sum - mat[n / 2][n / 2];
    }
};