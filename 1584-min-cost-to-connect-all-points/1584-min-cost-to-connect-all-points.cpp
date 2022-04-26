class Solution {
  public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
      int n = points.size();
      int ans = 0;
        
      vector<int> dist(n, INT_MAX);
      vector<bool> vis(n, false);
      dist[0] = 0;
        
      for (int i = 0; i < n; i++)
      {
        int currMin = INT_MAX;
        int curr = -1;
        for (int k = 0; k < n; k++) 
        {
          if (!vis[k] && currMin > dist[k]) 
          {
            currMin = dist[k];
            curr = k;
          }
        }

        ans += currMin;
        vis[curr] = true;

        for (int j = 0; j < n; j++) 
        {
          int d = abs(points[curr][0] - points[j][0]) + abs(points[curr][1] - points[j][1]);
            
          if (d < dist[j] && !vis[j]) 
          {
            dist[j] = d;
          }
        }
      }
      return ans;
    }
};