class Solution {
public:
    void transpose(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        int n = a.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                b[i][j] = a[j][i];
            }
        }
    }
    
    int equalPairs(vector<vector<int>>& grid) 
    {        
        int n = grid.size();
        int ans = 0;
        
        vector<vector<int>> trans(n, vector<int>(n));
        transpose(grid, trans);
                
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // this line checks every row with all the other rows of the transpose matrix
                if(grid[i] == trans[j]) 
                    ans++;
            }
        }
        
        return ans;       
    }
};