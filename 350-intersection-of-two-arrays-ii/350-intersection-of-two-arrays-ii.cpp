class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(auto it : nums1)
        {
            mp[it]++;
        }
        
        for(int i = 0; i < nums2.size(); i++)
        {
            auto it = mp.find(nums2[i]);
            if(it != mp.end() && it->second > 0)
            {
                ans.push_back(nums2[i]);
                it->second--;
            }
        }
        return ans;
    }
};