class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int start = 0, end = -1;
        int n = nums.size();
        
        int maxi = nums[0];
        int mini = nums[n - 1];
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < maxi)
                end = i;
            else
                maxi = nums[i];
        }
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] > mini)
                start = i;
            else
                mini = nums[i];
        }
        
        return end - start + 1;
    }
};