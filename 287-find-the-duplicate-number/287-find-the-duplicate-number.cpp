class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int duplicate;
        
        for(auto it : nums)
        {
            mp[it]++;
        }
        
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                duplicate = it.first;
                break;
            }           
        }
        
        return duplicate;
    }
};