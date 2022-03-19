class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> temp;
        
        for(auto it : magazine)
            temp[it]++;
        
        for(int i = 0; i < ransomNote.length(); i++)
        {
            if(--temp[ransomNote[i]] < 0)
                return false;
        }
        
        return true;
    }
};