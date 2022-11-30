class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<int> zR(r);
        vector<int> zC(c);
        vector<int> oR(r);
        vector<int> oC(c);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    oR[i]++;
                    oC[j]++;
                }
                else
                {
                    zR[i]++;
                    zC[j]++;
                }
            }
        }

        // Now calculate the difference
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = oR[i] + oC[j] - zR[i] - zC[j];
            }
        }

        return grid;
    }
};