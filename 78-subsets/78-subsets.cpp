class Solution {
public:
    void generateSubsets(int idx, vector<int> ans, vector<int> nums, vector<vector<int>> &res)
    {
        if(idx == nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        // Pick a number
        ans.push_back(nums[idx]);
        generateSubsets(idx + 1, ans, nums, res);
        ans.pop_back();
        
        // Do not pick a number
        generateSubsets(idx + 1, ans, nums, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> ans;
        vector<vector<int>> res;
        
        generateSubsets(0, ans, nums, res);
        
        return res;
    }
};