class Solution {
public:
    
    set<vector<int>> s;
    
    void permutation(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index == nums.size() && s.find(nums) == s.end())
        {
            ans.push_back(nums);
            s.insert(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permutation(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        permutation(0, nums, ans);
        return ans;        
    }
};