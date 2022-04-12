class Solution {
public:
    
    int getLiveNeigh(vector<vector<int>>& temp, int i, int j, int m, int n) 
    {
        int liveNeigh = 0;
        
        if(i > 0) 
        {
            if(temp[i - 1][j] == 1) 
            {
                liveNeigh++;
            }
        } 
        
        if(i < m - 1)
        {
            if(temp[i + 1][j] == 1)
            {
                liveNeigh++;
            }
        } 
        
        if(j > 0) 
        {
            if(temp[i][j - 1] == 1)
            {
                liveNeigh++;
            }
        }
        
        if(j < n - 1)
        {
            if(temp[i][j + 1] == 1)
            {
                liveNeigh++;
            }
        } 
        
        if(i > 0 && j > 0) 
        {
            if(temp[i - 1][j - 1] == 1)
            {
                liveNeigh++;
            }
        } 
        
        if(i < m - 1 && j < n - 1)
        {
            if(temp[i + 1][j + 1] == 1)
            {
                liveNeigh++;
            }
        } 
        
        if(i < m - 1 && j > 0)
        {
            if(temp[i + 1][j - 1] == 1) 
            {
                liveNeigh++;
            }
        } 
        
        if(i > 0 && j < n - 1)
        {
            if(temp[i - 1][j + 1] == 1)
            {
                liveNeigh++;
            }
        }
        
        return liveNeigh;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        vector<vector<int>> temp = board;
        
        int m = board.size();
	    int n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int res = getLiveNeigh(temp, i, j, m, n);
            
                if(board[i][j] == 0)
                {
                    if(res == 3)
                    {
                        board[i][j] = 1;
                    }
                } 
                else 
                {
                    if(res < 2 || res > 3)
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};