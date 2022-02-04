// 2 pointer approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int r = 0, l = 0;
        
        while(r < nums.size())
        {
            if(nums[r] != 0)
            {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
    }
};