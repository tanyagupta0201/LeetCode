class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' ||  ch == 'i' ||  ch == 'o' ||  ch == 'u')
            return true;
        
        if(ch == 'A' || ch == 'E' ||  ch == 'I' ||  ch == 'O' ||  ch == 'U')
            return true; 
        
        return false;
    }
    
    bool halvesAreAlike(string s) 
    {
        int c1 = 0, c2 = 0;
        
        for(int i = 0; i < s.length() / 2; i++)
        {
            if(isVowel(s[i]))
            {
                c1++;
            }
        }
        
        for(int i = s.length() / 2; i < s.length(); i++)
        {
            if(isVowel(s[i]))
            {
                c2++;
            }
        }
        
        if(c1 == c2)
            return true;
        
        return false;
    }
};