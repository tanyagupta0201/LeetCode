class Solution {
public:
    void generateSubsets(int idx, vector<int> &ans, vector<int> &nums, vector<vector<int>> &res)
    {
        res.push_back(ans);
            
        for(int i = idx; i < nums.size(); i++)
        { 
           if(i != idx && nums[i] == nums[i - 1]) // avoid duplicates
             continue;
        
           ans.push_back(nums[i]);
           generateSubsets(i + 1, ans, nums, res);
           ans.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> ans;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        generateSubsets(0, ans, nums, res);
        
        return res;        
    }
};