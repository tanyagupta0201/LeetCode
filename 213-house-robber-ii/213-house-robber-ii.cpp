class Solution {
public:
    int maxAdjSum(vector<int> &v)
    {
        int prev = v[0], prev2 = 0;
        int n = v.size();
        
        for(int i = 1; i < n; i++)
        {
            int take = v[i];
            if(i > 1) 
                take += prev2;
            
            int notTake = 0 + prev;
            
            int curr = max(take, notTake);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> v1, v2;
        
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            {
                // insert all elements except the first element
                v1.push_back(nums[i]);
            }
            
            if(i != n - 1)
            {
                // insert all elements except the last one
                v2.push_back(nums[i]);
            }
        }
        
        return max(maxAdjSum(v1), maxAdjSum(v2));
    }
};