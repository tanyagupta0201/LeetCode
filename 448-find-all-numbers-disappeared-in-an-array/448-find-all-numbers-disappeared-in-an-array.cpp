class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        
        map<int, int> mp;
        
        for(auto x : nums)
            mp[x]++;
        
        for(int i = 1; i <= n; i++)
        {
            if(mp.find(i) == mp.end())
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};