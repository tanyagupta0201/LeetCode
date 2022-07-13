// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    void dfs(int i, int j, int r, int c, vector<vector<char>> &grid)
    {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != 'X')
        {
            return;
        }
        
        grid[i][j] = 'Y'; // to mark visited
        
        dfs(i, j + 1, r, c, grid);
        dfs(i, j - 1, r, c, grid);
        dfs(i + 1, j, r, c, grid);
        dfs(i - 1, j, r, c, grid);
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int r = grid.size(), c = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 'X')
                {
                   cnt++;
                   dfs(i, j, r, c, grid);
                }
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends