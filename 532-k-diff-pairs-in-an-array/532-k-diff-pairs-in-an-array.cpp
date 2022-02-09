// https://youtu.be/bAM0rffFsQw

class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        if(k < 0)
            return 0;
        
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        int c = 0;
        
        if(k == 0)
        {
            for(auto x: m)
            {
                if(x.second > 1)
                {
                    c++;
                }
            }
            return c;
        }
        
        for(auto x: m)
        {
            if(m.count(x.first - k))
                c++;
        }
        return c;
    }
};