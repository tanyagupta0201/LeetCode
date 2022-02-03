class Solution {
public:
    
/* Method 1

    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
    
*/
    // Method 2: 
    // 2 Pointer Approach
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int start = 0;
        int end = nums.size() - 1;
        int lastPos = nums.size() - 1;
        
        vector<int> ans(nums.size());
        
        while(lastPos >= 0)
        {
            if(abs(nums[start]) >= abs(nums[end]))
            {
                ans[lastPos] = nums[start] * nums[start];
                start++;
            }
            else
            {
                ans[lastPos] = nums[end] * nums[end];
                end--;
            }
            lastPos--;
        }
        return ans;
    }
};