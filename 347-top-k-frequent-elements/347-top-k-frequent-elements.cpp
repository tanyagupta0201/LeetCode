class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(auto it : nums)
            mp[it]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        
        vector<int> ans;
        
        while(k > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};