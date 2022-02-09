// https://youtu.be/tHNsZHXnYd4

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        
        int ma = ans; // to store maximum product
        int mi = ans; // to store minimum product
        
        int n = nums.size();
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < 0)
            {
                swap(mi, ma);
            }
            
            ma = max(nums[i], ma * nums[i]);
            mi = min(nums[i], mi * nums[i]);
            
            ans = max(ans, ma);
        }
        return ans;
    }
};