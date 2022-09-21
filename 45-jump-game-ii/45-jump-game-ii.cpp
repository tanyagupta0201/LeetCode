class Solution {
public:
    int jump(vector<int>& nums)
    {
        int curr = 0, farthest = 0, jumps = 0;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, nums[i] + i); // the farthest index that we can reach
            
            // we will check for all the index till farthest
            // when we will find the most optimal path we will increase jumps and change the position of curr
            if(i == curr)
            {
                jumps++;
                curr = farthest;
            }
        }
        
        return jumps;
    }
};