class Solution {
public:
    bool palindrome(string s, int i, int j)
    {        
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) 
    {
        int i = 0, j = s.size() - 1;
        
        // Agar pehle se hi palindrome ho toh
        if(palindrome(s, i, j))
        {
            return true;
        }
        
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                // Dono characters ko remove karke dekhenge(start aur end dono taraf se)
                return palindrome(s, i + 1, j) || palindrome(s, i, j - 1);
            }
             
            i++;
            j--;
        }
        
        return true;
    }
};