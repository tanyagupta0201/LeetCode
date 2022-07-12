class Solution {
public:
    
    void dfs(int node, vector<int> &vis, vector<vector<int>> &isConnected)
    {
        vis[node] = 1;
        
        // isConnected -> matrix hai not adj list
        for(int i = 0; i < isConnected[node].size(); i++)
        {
            if(isConnected[node][i] && !vis[i])
            {
                dfs(i, vis, isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0;
        
        int n = isConnected.size();
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                provinces++;
                dfs(i, vis, isConnected);
            }
        }
        return provinces;
    }
};