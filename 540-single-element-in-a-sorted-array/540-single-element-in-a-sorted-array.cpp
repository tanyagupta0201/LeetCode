class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        
        int low = 0, high = n - 2;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == nums[mid ^ 1])
            {
                // shrink left half
                low = mid + 1;
            }
            else
            {
                // shrink right half
                high = mid - 1;
            }
        }
        
        // at the end, low will cross high and reach the desired number
        return nums[low];
    }
};