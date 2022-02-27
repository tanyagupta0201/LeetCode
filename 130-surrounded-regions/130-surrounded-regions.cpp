class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if(board[i][j] == 'O')
        {
            board[i][j] = '1';
            
            if(i + 1 < board.size()) 
                dfs(board, i + 1, j);
            
            if(i > 1) 
                dfs(board, i - 1, j);
        
            if(j + 1 < board[i].size()) 
                dfs(board, i, j + 1);
        
            if(j > 1) 
                dfs(board, i, j - 1);
        }
        
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();
        
        // Mark all the inavlid zeros as 1
        // ie. mark all the zeros present at the corners and the zeros connected to it
        
        // First row and last row
        for(int i = 0; i < rows; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        
        // First col and last col
        for(int j = 1; j < cols - 1; j++)
        {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if (board[i][j] == '1') 
                    board[i][j] = 'O';
            }
        }
        
    }
};