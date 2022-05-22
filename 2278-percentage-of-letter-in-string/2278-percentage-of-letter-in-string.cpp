class Solution {
public:
    int percentageLetter(string s, char letter)
    {
        int n = s.length();
        int c = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == letter)
            {
                c++;
            }
        }
        
        int perc = (c * 100 ) / n;
        
        return perc;        
    }
};