// https://youtu.be/Y7LiLNdayF0

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        
        int low = 0;
        int high = nums.size() - 1;
        
        // to find first index
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
            {
                v[0] = mid;
                // continue searching left part
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        
        low = 0;
        high = nums.size() - 1;
        
        // to find last index
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
            {
                v[1] = mid;
                // continue searching right part
                low = mid + 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return v;        
    }
};