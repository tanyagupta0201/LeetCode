// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        if(grid.empty())
           return 0;
           
         int r = grid.size();
         int c = grid[0].size();
         int nonZero = 0;
         queue<pair<int, int>> q; // {x, y} dimensions
         
         for(int i = 0; i < r; i++)
         {
             for(int j = 0; j < c; j++)
             {
                 if(grid[i][j] == 2)
                 {
                     q.push({i, j});
                 }
                 
                 if(grid[i][j] != 0)
                 {
                     nonZero++;
                 }
             }
         }
         
         // 4 possible directions
         int dx[4] = {0, 0, 1, -1};
         int dy[4] = {1, -1, 0, 0};
         
         int time = 0, cnt = 0;
         
         while(!q.empty())
         {
             int sz = q.size();
             cnt += q.size();
             
             while(sz--)
             {
                 auto it = q.front();
                 q.pop();
                 
                 int i = it.first;
                 int j = it.second;
                 
                 for(int k = 0; k < 4; k++)
                 {
                     int xCordinate = i + dx[k];
                     int yCordinate = j + dy[k];
                     
                     // these are all invalid conditions
                     if(xCordinate < 0 || xCordinate >= r || yCordinate < 0 || yCordinate >= c || grid[xCordinate][yCordinate] != 1)
                     {
                         continue;
                     }
                     
                     grid[xCordinate][yCordinate] = 2;
                     q.push({xCordinate, yCordinate});
                 }
             }
             
             if(!q.empty())
             {
                 time += 1;
             }
         }
         
         if(cnt == nonZero)
         {
             return time;
         }
         else
         {
             return -1;
         }
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends