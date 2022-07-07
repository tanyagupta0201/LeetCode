// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	// Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // insert first node
        pq.push({0, src}); // (dist, node)
        
        while(!pq.empty())
        {
            pair<int, int> prevNode = pq.top(); 
            pq.pop();
            
            //vector<pair<int, int>> ::iterator it;
            for(auto it : adj[prevNode.second])
            {
                // adj -> (node, dist)
                int nextNode = it[0];
                int nextDist = it[1];
                
                if(dis[prevNode.second] + nextDist < dis[nextNode])
                {
                    dis[nextNode] = dis[prevNode.second] + nextDist;
                    pq.push({dis[nextNode], nextNode});
                }
            }
        }
        
        return dis;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends