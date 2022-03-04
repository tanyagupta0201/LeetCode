class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int r = 0, l = 0, n = nums.size(), sum = 0, ans = INT_MAX;
        
        while(r < n)
        {
            sum += nums[r];
            r++;
            
            while(sum >= target)
            {
                ans = min(ans, r - l);
                sum -= nums[l];
                l++;
            }
        }
        // If there is no such subarray then return 0
        return ans == INT_MAX ? 0 : ans;

    }
};