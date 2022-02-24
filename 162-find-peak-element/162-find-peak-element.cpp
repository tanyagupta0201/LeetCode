class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size();
        
        int lo = 0;
        int hi = n - 1;
        
        while(lo < hi)
        {
            int mid = (lo + (hi - lo) / 2);
            
            if(mid == 0)
            {
                if(nums[mid] > nums[mid + 1])
                    return mid;
                
                lo = mid + 1;
            }
            
            else if(mid ==  n - 1)
            {
                if(nums[mid] > nums[mid - 1])
                    return mid;
                
                hi = mid - 1;
            }
            
            else if(mid > 0 && mid < n - 1)
            {
                if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                {
                    return mid;
                }
                
                else if(nums[mid + 1] > nums[mid])
                {
                    lo = mid + 1;
                }
                
                else 
                {
                    hi = mid - 1;
                }
            }               
        }  
        return lo;
    }
};