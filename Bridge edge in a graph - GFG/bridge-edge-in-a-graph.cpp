// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    vector<pair<int, int>> v;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &disc, vector<int> &low, int &timer)
    {
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        
        for(auto nbr : adj[node])
        {
            if(nbr == parent)
               continue;
               
            if(!vis[nbr])
            {
                dfs(nbr, node, vis, adj, disc, low, timer);
                low[node] = min(low[node], low[nbr]); 
                
                if(low[nbr] > disc[node])
                {
                    v.push_back({node, nbr});
                }
            }
            else
            {
                // if visited
                low[node] = min(low[node], disc[nbr]); 
            }
        }
    }
    
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        int timer = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, vis, adj, disc, low, timer);
            }
        }
        
        for(int i = 0; i < v.size(); i++)
        {
            auto it = v[i];
            
            if((it.first == c && it.second == d) || (it.first == d && it.second == c))
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends