class Solution {
public:
    char repeatedCharacter(string str) 
    {
        int n = str.length();
        unordered_set<char> s;
        
        for(int i = 0; i < n; i++)
        {
            // take each character one by one
            char ch = str[i]; 
            
            // if char is already present it is the duplicate
            if(s.find(ch) != s.end())
                return ch;
            // insert the char in the set
            else
                s.insert(ch);
        }
        
        // if there is no duplicate char
        return ' ';
    }
};