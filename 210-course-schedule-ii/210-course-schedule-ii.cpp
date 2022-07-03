class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++; // adj node wale ki indegree increase hogi na 
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // Perform BFS
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }  
        }
        
        if(ans.size() != numCourses)
        {
            ans.clear();
        }
        
        return ans;
    }
};