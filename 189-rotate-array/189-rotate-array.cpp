class Solution {
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while(start < end)
        {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
    
    void rotate(vector<int>& nums, int k) 
    {
        int l = nums.size();
        k = k % l;
        
        reverse(nums, 0, l  - 1);
        reverse(nums, 0, k  - 1);
        reverse(nums, k, l  - 1);
    }
};