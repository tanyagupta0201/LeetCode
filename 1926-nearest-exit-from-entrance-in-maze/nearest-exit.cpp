class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();

        int steps = 1;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // taaki wapas entrance par na aaye

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int x = q.front().first;  // row
                int y = q.front().second; // col
                q.pop();

                // traverse in all 4 directions
                for (int i = 0; i < 4; i++)
                {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX < 0 || newY < 0 || newX >= m || newY >= n || maze[newX][newY] == '+')
                        continue;

                    if (newX == 0 || newY == 0 || newX == m - 1 || newY == n - 1)
                        return steps;

                    q.push({newX, newY});
                    maze[newX][newY] = '+'; // mark visited
                }
            }

            steps++;
        }

        return -1;
    }
};