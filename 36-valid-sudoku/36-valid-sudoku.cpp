class Solution {
public:
    
    bool check1(vector<vector<char>> &board)
    {
        //check all rows;
        for(int i = 0; i < 9; i++) 
        {
            vector<bool> vis(10, false);
            
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    
                    if(vis[num]) 
                        return false;
                    
                    vis[num] = true;
                }
            }
        }
        return true;
    }
    
    bool check2(vector<vector<char>> &board)
    {
        // check all columns
        for(int j = 0; j < 9; j++)
        {
            vector<bool> vis(10, false);
            
            for(int i = 0; i < 9; i++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                
                    if(vis[num]) 
                        return false;
               
                    vis[num] = true;
                }
            }
        }
        return true;
    }

    bool check3(vector<vector<char>> &board)
    {
        // check all submatrix
        for(int k = 0; k < 3; k++)
        {
            int sr = k * 3;
            int sc = 0;
        
            for(int l = 0; l < 3; l++)
            {
                sc = l * 3;
                
                vector<bool> vis(10, false);
            
                for(int i = sr; i < sr + 3; i++)
                {
                    for(int j = sc; j < sc + 3; j++)
                    {
                        if(board[i][j] != '.')
                        {
                            int num = board[i][j] - '0';
                        
                            if(vis[num]) 
                                return false;
                        
                            vis[num] = true;
                        }
                    }
                }
            }
       }
       return true;
    }


    bool isValidSudoku(vector<vector<char>> &board) 
    {
        return check1(board) && check2(board) && check3(board);
    }  
};