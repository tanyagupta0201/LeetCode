class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            int freq = it.second; // frequency of each element
            
            // Number of pairs for each number
            ans += (freq * (freq - 1)) / 2;
        }
        
        return ans;
    }
};