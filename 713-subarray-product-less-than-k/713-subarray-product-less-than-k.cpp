class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
       long long int start = 0, end = 0, res = 0, p = 1;
        
        for(end = 0; end < nums.size(); end++)
        {
            p = p * nums[end];
            
            while(start < nums.size() and p >= k)
            {
                p = p / nums[start];
                start++;
            }
            
            if(p < k)
            {
                res += end - start + 1;     
            }
        }
        return res;
    }
};