class Solution
{
public:
    bool isValid(vector<int> &pos1, vector<int> &pos2)
    {
        return pos1[0] == pos2[0] || pos1[1] == pos2[1];
    }

    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;

        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i])
                continue;

            if (isValid(graph[node], graph[i]))
                dfs(i, graph, visited);
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, false);

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            dfs(i, stones, visited);
            components++;
        }

        return n - components;
    }
};