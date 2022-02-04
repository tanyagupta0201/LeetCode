class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        int i = 0, j = nums.size() - 1;
        
        while( i < j)
        {
            int currSum = nums[i] + nums[j];
            
            if(currSum > target)
                j--;
            else if(currSum < target)
                i++;
            else if(currSum == target)
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                return v;
            }
        }
       return v; 
    }
};