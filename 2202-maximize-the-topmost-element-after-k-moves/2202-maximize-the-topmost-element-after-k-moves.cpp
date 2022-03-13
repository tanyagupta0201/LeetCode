// https://youtu.be/bxM0OAFPYT0

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int ans = 0;
        
        // if `N == 1`, we can return the topmost element if `k` is a even number 
        // keep removing the topmost element and adding it back
        if(n == 1 && k % 2) 
        {
            return - 1;
        }
        
        // In k = 1 case, we can only remove the first element, so we have no choice but return the element at index 1
        if(k == 1)
        {
            return nums[1];
        }
        
        if(k > n)
        {
            for(int i = 0; i < n; i++)
                ans = max(ans, nums[i]);
            
            return ans;
        }
        else if(k == n)
        {
            for(int i = 0; i < k - 1; i++)
                ans = max(ans, nums[i]);
            
            return ans;
        }
        else
        {
            for(int i = 0; i < k - 1; i++)
                ans = max(ans, nums[i]);
            
            return max(ans, nums[k]);
        }
    }
};