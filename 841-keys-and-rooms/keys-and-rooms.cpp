class Solution
{
public:
    // simple DFS, If any of the node is unvisited then return false

    void dfs(int i, vector<bool> &vis, vector<vector<int>> &rooms)
    {
        vis[i] = 1;

        for (auto room : rooms[i])
        {
            if (!vis[room])
            {
                dfs(room, vis, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(0, vis, rooms);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }

        return true;
    }
};