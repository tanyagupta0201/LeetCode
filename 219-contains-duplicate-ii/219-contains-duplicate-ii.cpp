class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        vector<pair<int, int>> v; // (number, index)
        
        for(int i = 0; i < nums.size(); i++)
        {
            v.push_back(make_pair(nums[i], i));
        }
        
        // Before Sorting
        // 1 2 3 1 -> element
        // 0 1 2 3 -> index
        
        sort(v.begin(), v.end());
        
        // After Sorting
        // 1 1 2 3 -> element
        // 0 3 1 2 -> index
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if((v[i].first == v[i + 1].first) && abs(v[i].second - v[i + 1].second) <= k)
                return true;
        }
        
        return false;
    }
};