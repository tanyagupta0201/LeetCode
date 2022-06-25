// https://www.youtube.com/watch?v=iL7oSNc3OXA

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int pos= -1;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                if(pos != -1) // matlab pehle bhi pos change ho chuki hai
                    return false;
                
                pos = i;
            }
        }
        
        return pos == -1 || pos == 0 || pos == nums.size() - 2 || nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2];
        
    }
};