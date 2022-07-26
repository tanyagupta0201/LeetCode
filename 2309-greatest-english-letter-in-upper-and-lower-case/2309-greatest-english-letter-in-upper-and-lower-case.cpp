class Solution {
public:
    string greatestLetter(string s)
    {
        int n = s.length();
        
        sort(s.begin(), s.end());
        
        for(int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];
            char u = toupper(ch);
            char l = tolower(ch);
            
            if((s.find(u) != string::npos) && (s.find(l) != string::npos))
            {
                string str;
                str += u;
                return str;
            }
        }
        return "";
    }
};