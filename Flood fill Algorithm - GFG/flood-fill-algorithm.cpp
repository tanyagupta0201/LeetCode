// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int r, int c, int oldColor, int newColor)
    {
        if(sr < 0 || sr >= r || sc < 0 || sc >= c || image[sr][sc] != oldColor)
        {
            return;
        }
        
        image[sr][sc] = newColor;
        
        dfs(image, sr + 1, sc, r, c, oldColor, newColor);
        dfs(image, sr - 1, sc, r, c, oldColor, newColor);
        dfs(image, sr, sc - 1, r, c, oldColor, newColor);
        dfs(image, sr, sc + 1, r, c, oldColor, newColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int r = image.size(), c = image[0].size();
        
        if(image[sr][sc] == newColor)
            return image;
            
        int oldColor = image[sr][sc];
        
        dfs(image, sr, sc, r, c, oldColor, newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends