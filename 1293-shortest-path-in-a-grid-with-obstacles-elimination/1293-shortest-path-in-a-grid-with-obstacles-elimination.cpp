class Solution
{
public:
    int r, c, steps;

    bool isValid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        r = grid.size();
        c = grid[0].size();
        steps = 0;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        bool vis[r + 1][c + 1][k + 1];
        memset(vis, 0, sizeof(vis));
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        vis[0][0][0] = 1;
        
        while (!q.empty())
        {
            int n = q.size();
            
            for (int i = 0; i < n; i++)
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int tk = q.front().second;
                
                q.pop();

                if (x == r - 1 && y == c - 1)
                    return steps;

                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    if (!isValid(nx, ny))
                        continue;

                    int nk = tk + grid[nx][ny];
                    
                    if (nk > k || vis[nx][ny][nk])
                        continue;

                    q.push({{nx, ny}, nk});
                    vis[nx][ny][nk] = 1;
                }
            }
            steps++;
        }
        
        return -1;
    }
};