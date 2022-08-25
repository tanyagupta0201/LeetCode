class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;
        
        for(auto it: magazine)
            mp[it]++;
        
        for(int i = 0; i < ransomNote.size(); i++)
        {
            // Each character in magazine should be equal or greater than the number of characters in ransomNote 
            // If not then return false
            if(--mp[ransomNote[i]] < 0)            
                return false;
        }
        
        return true;        
    }
};