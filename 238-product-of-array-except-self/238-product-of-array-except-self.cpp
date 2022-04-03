class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> pre(n), suff(n);
        
        pre[0] = 1;
        suff[n - 1] = 1;
        
        // Compute prefix array
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        
        // Compute suffix array
        for(int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        
        for(int i = 0; i < n; i++)
        {
            nums[i] = pre[i] * suff[i];
        }
        
        return nums;
    }
}; 



// SOLUTION 2
// Without using extra space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prod(n, 1);
        
        int temp = 1;
        
        // In this loop, temp variable contains product of elements on left side excluding nums[i]
        for(int i = 0; i < n; i++)
        {
            prod[i] *= temp;
            temp *= nums[i];
        }
        
        temp = 1;
 
       // In this loop, temp variable contains product of elements on right side excluding nums[i] 
       for (int i = n - 1; i >= 0; i--)
       {
            prod[i] *= temp;
            temp *= nums[i];
       }
 
        return prod;
    }
};
