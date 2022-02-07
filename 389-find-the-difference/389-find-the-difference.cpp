class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char c = 0;
        
        for(char i: s)
            c = c ^ i;
        
        for(char j: t)
            c = c ^ j;
        
        return c;  
    }
};