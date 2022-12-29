/*
    The problem asks us to divide the given people into two groups such that no two people in the same group dislike each other.

    We can represent this problem in the form of a graph, with people being the nodes and disliked pairs being the edges.
    Our task is to figure out whether we can divide the nodes into two sets such that there aren't any edges between nodes of the
    same set.

    A graph satisfying the above condition is said to be a bipartite graph.

*/

class Solution
{
public:
    bool bfs(int firstNode, vector<int> &color, vector<int> adj[])
    {
        queue<int> q;
        q.push(firstNode);
        color[firstNode] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr])
            {
                if (color[it] == -1)
                {
                    q.push(it);
                    color[it] = 1 - color[curr]; // mark with opposite color
                }
                // if already colored
                else if (color[it] == color[curr])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];

        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, color, adj))
                {
                    return false;
                }
            }
        }

        return true;
    }
};