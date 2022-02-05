class Solution {
public:
    string reverseWords(string s)
    {
        int l = 0, r = 0;
        
        while(l < s.size())
        {
            while(r < s.size() && s[r] != ' ')
            {
                r++;
            }
            
            reverse(s.begin() + l, s.begin() + r);
            
            l = r + 1; // space + 1
            r = l;
        }
        return s;
    }
};
