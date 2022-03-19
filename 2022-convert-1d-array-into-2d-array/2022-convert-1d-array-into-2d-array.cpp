class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        vector<vector<int>> ans(m, vector<int> (n));
        
        // if the size of original array is lesser than or greater than original array, 2D array cannot be made
        if(original.size() != m * n)
            return {};
        
        for(int i = 0; i < original.size(); i++)
        {
            ans[i / n][i % n] = original[i];
        }
        
        return ans;        
    }
};