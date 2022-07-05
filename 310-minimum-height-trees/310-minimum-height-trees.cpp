// https://www.youtube.com/watch?v=g_DshK0nnmI&t=1325s

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans; // to store final answer
        
        // if node is 1 then height will be 0
        if(n == 1)
        {
            ans.push_back(0);
            return ans;
        } 
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // make adj list and count the indegree of each node
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        // now insert all the nodes having ingree 1 into the queue
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 1)
                q.push(i);
        }
        
        while(!q.empty())
        {
            ans.clear(); // har new iteration se pehle clear karna hai 
            int size = q.size();
            
            while(size--)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                
                for(auto nbr : adj[curr])
                {
                    indegree[nbr]--;
                    
                    if(indegree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        
        return ans;        
    }
};