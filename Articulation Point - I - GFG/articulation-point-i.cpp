// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &low, vector<int> &disc, vector<int> &arti, int timer)
    {
        vis[node] = 1;
        low[node] = disc[node] = timer++;
        int child = 0;
        
        for(auto it : adj[node])
        {
            if(it == parent)
               continue;
               
            if(!vis[it])
            {
                dfs(it, node, adj, vis, low, disc, arti, timer);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= disc[node] && parent != -1)
                {
                    arti[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
        }
        
        if(parent == -1 && child > 1)
        {
            arti[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]) 
    {
        vector<int> vis(n, 0);
        vector<int> low(n, -1), disc(n, -1);
        vector<int> arti(n, 0);
        int timer = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, adj, vis, low, disc, arti, timer);
            }
        }
        
        int cnt = 0;
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(arti[i] == 1)
            {
                ans.push_back(i);
                cnt++;
            }
        }
        
        if(cnt == 0)
        {
            return {-1};
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends