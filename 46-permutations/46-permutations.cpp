// https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

// Better Approach
class Solution {
public:
    void permutation(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permutation(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        permutation(0, nums, ans);
        return ans;        
    }
};