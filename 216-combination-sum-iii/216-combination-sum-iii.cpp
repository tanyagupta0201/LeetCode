class Solution {
public:
    void combinations(int k, int target, vector<vector<int>> &ans, vector<int> ds, int idx)
    {
        // Base Case
        if(ds.size() == k)
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        // Pick an element
        for(int i = idx; i <= 9; i++) // Need to pick up elements from 1 to 9
        {
            ds.push_back(i);
            combinations(k, target - i, ans, ds, i + 1);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        
        combinations(k, n, ans, ds, 1);
        
        return ans;
    }
};