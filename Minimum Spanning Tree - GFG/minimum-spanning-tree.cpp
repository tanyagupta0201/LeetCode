// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> mst(n, false);
        vector<int> dist(n, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        
        dist[0] = 0;
        pq.push({0, 0});
        
        
        while(!pq.empty())
        {
            int currNode = pq.top().second;
            pq.pop();
            
            mst[currNode] = true;
            
            for(auto it : adj[currNode])
            {
                int nextNode = it[0];
                int wt = it[1];
                
                if(mst[nextNode] == false && dist[nextNode] > wt)
                {
                    dist[nextNode] = wt;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += dist[i];
        }
        
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends