// https://youtu.be/wtRT9G42g4g

class Solution {
public:
    bool checkValid(int i, int j, int m, int n)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        queue<pair<int, int>> q; // value and cordinate
        
        vector<vector<int>> ans(mat.size(), vector<int> (mat[0]. size(), -1));
        
        // Starting nodes are 0 => mark them in ans as 0 because distance from a 0 cell is 0
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        } 
        
        // BFS
        int m = mat.size();
        int n = mat[0].size();
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            
            // Check for its neighbours
            // If they are valid and not visited, add them in the queue
            
            if(checkValid(i + 1, j, m, n) && ans[i + 1][j] == -1)
            {
                q.push({i + 1, j});
                ans[i + 1][j] = ans[i][j] + 1;
            }
            
            if(checkValid(i - 1, j, m, n) && ans[i - 1][j] == -1)
            {
                q.push({i - 1, j});
                ans[i - 1][j] = ans[i][j] + 1;
            }
            
            if(checkValid(i, j + 1, m, n) && ans[i][j + 1] == -1)
            {
                q.push({i, j + 1});
                ans[i][j + 1] = ans[i][j] + 1;
            }
            
            if(checkValid(i, j - 1, m, n) && ans[i][j - 1] == -1)
            {
                q.push({i, j - 1});
                ans[i][j - 1] = ans[i][j] + 1;
            }
               
            q.pop();
        }
        return ans;
    }
};