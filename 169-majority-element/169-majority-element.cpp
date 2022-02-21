// https://leetcode.com/problems/majority-element/discuss/1787865/C%2B%2Bor-Detailed-Explanation-w-FUNNY-STORY-or-Two-Approaches-or-DRY-RUN

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        
        int hero = nums[0]; // Abhi 1st element ko majority maan rahe hain
        int power = 1;      // Atleast 1 power toh hogi hi
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == hero)
            {
                power++;
            }
            else
            {
                power--;
                
                if(power == 0)
                {
                    hero = nums[i];
                    power = 1;
                }
            }
        }
        
        return hero;
    }
};