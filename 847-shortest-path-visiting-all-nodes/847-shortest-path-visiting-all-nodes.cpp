// You have to start BFS starting from all points
// Basic BFS with visited nodes will not work
// Avoid indefinite loops

// https://youtu.be/TmRk2F9L3Jw
class Solution {
    int solve(vector<vector<int>>&graph)
    {
        int n = (int)graph.size();
        int all = (1 << n) - 1; // 1000 -> 1100 - > 1111 -> 10000 - 1 = 1111
        
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>vis;
        
        for(int i = 0 ; i<n; i++)
        {
            int mask = (1 << i); // 2^i
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        while(!q.empty()) 
        {
            auto node = q.front();
            q.pop(); 
            
            int val = node.first , dist = node.second.first , mask = node.second.second;
            
            for(auto temp : graph[val])
            {
                int newMask = (mask | (1 << temp)); // 0001 | 0010 = 0011
                
                if(newMask == all)
                {
                    return dist + 1;
                }
                else if(vis.count({temp,newMask}))
                {
                    continue;
                }
                
                vis.insert({temp,newMask});
                q.push({temp,{dist+1,newMask}});
            }
        }
        return 0;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        if((int)graph.size() == 1)
        {
            return 0;
        }
        
        return solve(graph);
    }
};