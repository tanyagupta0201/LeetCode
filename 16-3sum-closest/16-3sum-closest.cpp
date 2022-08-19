class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        int sum = 0;
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int first = nums[i];
            int lo = i + 1, hi = nums.size() - 1;
            
            
            while(lo < hi)
            {
                if(first + nums[lo] + nums[hi] == target)
                    return target;
                
                else if(abs(first + nums[lo] + nums[hi] - target) < diff)
                {
                    // update the mini diff
                    diff = abs(first + nums[lo] + nums[hi] - target); 
                    sum =  first + nums[lo] + nums[hi];
                }
                
                if(first + nums[lo] + nums[hi] > target)
                    hi--;
                else
                    lo++;
            }
        }
        return sum;
    }
};