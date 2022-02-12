class Solution {
public:
    void solve(int index, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        // Base case, we get ans when a combination has k elements
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        
        // Iterate through loop from 1 till n
        // Add i to the temporary combination
        // Call recursively by passing index as i + 1 as we only need numbers which comes after the current element 
        for(int i = index; i <= n; i++)
        {
            temp.push_back(i);
            
            solve(i + 1, n, k, temp, ans);
        
            temp.pop_back(); // last se ek ek element nikaalte jaao
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(1, n, k, temp, ans);
        
        return ans;
    }
};