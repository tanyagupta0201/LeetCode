class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        vector<pair<int, int>> v; // (element, index)
        
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
        
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = i + 1; j < v.size() && v[j].first * 1L - v[i].first <= t; j++)
            {
               if(abs(v[j].second-v[i].second) <= k)
                   return true;
            }
        }
               
        return false;
    }
};