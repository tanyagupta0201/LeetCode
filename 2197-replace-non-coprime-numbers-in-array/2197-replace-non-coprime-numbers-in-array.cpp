class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            int y = nums[i];
            
            while(v.size() > 0 && __gcd(v.back(), y) > 1)
            {
                int x = v.back();
                v.pop_back();
                
                y = (x / __gcd(x, y)) * y; // stores LCM               
            }
            
            v.push_back(y);
        } 
        
        return v;
    }
};