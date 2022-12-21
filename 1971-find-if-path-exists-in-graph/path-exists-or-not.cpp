/*
   simple BFS Ques, just traversethe entire graph, keep updating visited array
   if visited[source] = 1, that meansit is visited and thee exists a path
*/

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        if (vis[destination] == 0)
            return false;
        return true;
    }
};