class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        map<int, int> mp; // stores value in sorted order
        
        for(int i = 0; i < nums.size(); i++)
        {
            // value -> index
            mp[nums[i]] = i;
        }
        
        for(auto it: operations)
        {
            int val = it[0];
            int replace = it[1];
            
            // jis index par nayi value laani hai
            int index = mp[val];
            
            // map mein se wo value erase kardo
            mp.erase(val);
            
            // replace value ke saath index ko link karo
            mp[replace] = index;
            
            // nums array mein uss index par replace value daal do
            nums[index] = replace;
        }
        
        return nums;
    }
};