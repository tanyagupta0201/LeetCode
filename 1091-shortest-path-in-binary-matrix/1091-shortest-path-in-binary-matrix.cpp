class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // If the staring cell is blocked then we simply return -1
        if (grid[0][0])
            return -1;

        // storing the size of the grid in n
        int n = grid.size();

        // Variable to keep track of the current layer
        int layer = 0;

        // Normal BFS implementation
        queue<vector<int>> q;
        q.push({0, 0});
        vector<vector<int>> visited(n, vector<int>(n, 0));
        while (!q.empty())
        {
            layer++;
            queue<vector<int>> temp;
            while (!q.empty())
            {
                int currX = q.front()[0];
                int currY = q.front()[1];
                q.pop();

                // If current is the destination cell then we return the current layer, which is the number of minimum steps required to reach destination
                if (currX == (n - 1) && currY == (n - 1))
                    return layer;

                // We can travel in all 8 direction
                int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
                int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
                for (int i = 0; i < 8; ++i)
                {
                    int newX = currX + x[i];
                    int newY = currY + y[i];

                    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && grid[newX][newY] == 0 && visited[newX][newY] == 0)
                    {
                        // Marking the neighbour as visited and pushing it to the temp variable
                        visited[newX][newY] = 1;
                        temp.push({newX, newY});
                    }
                }
            }

            // Coping temp to q
            q = temp;
        }

        // If we donot find the destination in all layers then we cannot reach the destination, so we return -1
        return -1;
    }
};