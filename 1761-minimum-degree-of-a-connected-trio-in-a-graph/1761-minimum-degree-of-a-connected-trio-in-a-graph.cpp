class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n + 1, vector<int> (n + 1, 0));
        vector<int> degree(n + 1, 0);
        
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            adj[u][v] = 1;
            adj[v][u] = 1;
            
            degree[u]++;
            degree[v]++;
        }
        
        // Check if trio exists for not, if exists find the min degree
        int mini = INT_MAX;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                for(int k = j + 1; k <= n; k++)
                {
                    // trio exists
                    if(adj[i][j] == 1 && adj[j][k] == 1 && adj[k][i] == 1)
                    {
                        // The degree of the trio is just degree(u) + degree(v) + degree(w) - 6. 
                        // The -6 comes from subtracting the edges u-v, u-w, and v-w, which are counted twice each in the vertex degree calculation.
                        mini = min(mini, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        
        // trio does not exists
        if(mini == INT_MAX)
            return -1;
        
        return mini;
    }
};