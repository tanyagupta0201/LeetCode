// explanation
// https://youtu.be/uG4M0qZ1L5U

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        int count = 1; // 1 chunk by default hoga
        int i = 0;
        
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] - nums[i] > k)
            {
                count += 1;
                i = j;
            }
        }
        return count;
    }
};