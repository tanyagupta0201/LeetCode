// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    bool dfs(int i, int j, int r, int c, vector<vector<int>> &grid)
    {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0)
            return false;
          
        if(grid[i][j] == 2)
            return true;
            
        grid[i][j] = 0; // vis ho gya isliye abb usse wall bana diya
        
        return (dfs(i + 1, j, r, c, grid) || dfs(i - 1, j, r, c, grid) || dfs(i, j - 1, r, c, grid) || dfs(i, j + 1, r, c, grid));
        
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1 && dfs(i, j, r, c, grid))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends