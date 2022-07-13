// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int dfs(int i, int j, int r, int c, vector<vector<int>> &grid)
    {
        int ar = 0;
        
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1)
            return 0;
            
        grid[i][j] = 2;
        ar++; // har dfs call ke liye ar increment hoga kyuki ek 1 wala square increase ho rha hai
        
        ar += dfs(i + 1, j + 1, r, c, grid);
        ar += dfs(i - 1, j + 1, r, c, grid);
        ar += dfs(i - 1, j - 1, r, c, grid);
        ar += dfs(i + 1, j - 1, r, c, grid);
        ar += dfs(i, j + 1, r, c, grid);
        ar += dfs(i, j - 1, r, c, grid);
        ar += dfs(i + 1, j, r, c, grid);
        ar += dfs(i - 1, j, r, c, grid);
        
        return ar;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid)
    {
        // Code here
        int r = grid.size(), c = grid[0].size();
        int area = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                area = max(area, dfs(i, j, r, c, grid));
            }
        }
        return area;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends