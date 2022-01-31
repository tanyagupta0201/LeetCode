class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int p = 0; // Pointer for string s
        int q = 0; // Pointer for string t
        
        if(s == "" && t == "")
            return true;
        
        for(int i = 0; i < t.size(); i++)
        {
            if(s[p] == t[q])
            {
                p++;
                q++;
            }
            else
            {
                q++;
            }
            
            if(p == s.size())
                return true;
        }
        return false;
    }
};