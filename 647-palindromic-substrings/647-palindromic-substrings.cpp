class Solution {
public:
    bool isPalindrome(int start, int end, string s)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            
            start += 1;
            end -= 1;
        }
        
        return true;
    }
    
    int countSubstrings(string s) 
    {
        int ans = 0;
        
        for(int start = 0; start < s.length(); start++)
        {
            for(int end = start; end < s.length(); end++)
            {
                if(isPalindrome(start, end, s))
                {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};