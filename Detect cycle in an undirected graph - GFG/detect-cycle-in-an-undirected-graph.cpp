// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkForCycle(vector<int> adj[], vector<int> &vis, int node, int V)
    {
        queue<pair<int, int>> q;
        
        // insert node and its parent in the queue
        q.push({node, -1}); // the first node has parent -1
        vis[node] = 1;
        
        while(!q.empty())
        {
            int temp = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            // Traverse through all its adjacent neighbours in the adjacency list
            for(auto it: adj[temp])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, temp});
                }
                else if(it != parent)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> vis(V, 0); // all nodes are unvisited
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(checkForCycle(adj, vis, i, V))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends