// https://youtu.be/PjKjbpI2Z3s

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        
        for(auto x : nums)
            mp[x]++;
        
        // Using lambda function
        sort(nums.begin(), nums.end(), [&](int a, int b)
        {
            return mp[a] != mp[b] ? mp[a] < mp[b] : a > b;            
        });
        
        return nums;        
    }
};