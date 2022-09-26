class Solution {
public:
    
    // d - 1, b - 2, c - 2, a - 1
    
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string, int> mp;
        
        for(auto it: arr)
            mp[it]++;
        
        for(auto letter: arr)
        {
            // if the freq is one, decrease the value of k
            if(mp[letter] == 1)
                k--;
            
            // as soon as k becomes 0, return that letter
            if(k == 0)
                return letter;
        }
        
        return "";
    }
};