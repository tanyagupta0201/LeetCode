class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        
        int dp[r][c];
        bool flag = false; // till now we have not seen obstacle
        
        // Fill 1st row
        for(int i = 0; i < c; i++)
        {
            if(flag || obstacleGrid[0][i] == 1)
            {
                flag = true;
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = 1;
            }
        }
        
        flag = false; // till now we have not seen obstacle
        // Fill 1st col
        for(int i = 0; i < r; i++)
        {
            if(flag || obstacleGrid[i][0] == 1)
            {
                flag = true;
                dp[i][0] = 0;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        
        for(int i = 1; i < r; i++)
        {
            for(int j = 1; j < c; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[r - 1][c - 1];
    }
};