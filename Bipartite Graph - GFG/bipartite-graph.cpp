// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    // -1 = not colored
    // 1 = first color
    // 0 = second color
    
    // BFS Traversal
    
    bool BFS(vector<int> adj[], vector<int> &color, int firstNode)
    {
        queue<int> q;
	    q.push(firstNode);
	    color[firstNode] = 1; // color it with any color
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto it: adj[node])
	        {
	            // if this adj node is not coloured then color it and put it inside the queue
	            if(color[it] == -1)
	            {
	                color[it] = 1 - color[node];
	                q.push(it);
	            }
	            // the adj node is already coloured 
	            // if its color is equal to the color of its parent 
	            // so the graph becomes non bipartite
	            else if(color[it] == color[node])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
    
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> color(V, -1);
	    
	     for(int i = 0; i < V; i++) // checking for all components
	     {
	         if(color[i] == -1)
	         {
	             if(!BFS(adj, color, i)) // agar ek bhi component bipartite nhi hai toh poora graph bipartite nhi hoga 
	                 return false;
	         }
	     }
	     
	     return true; // if neither of the component returned false
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends