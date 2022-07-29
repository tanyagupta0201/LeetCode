class Solution {
public:
    string truncateSentence(string s, int k)
    {        
        int cnt = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
           if(s[i] == ' ')
           {
               cnt++;
           }
            
            if(cnt == k)
            {
                s.erase(s.begin() + i, s.end());
                return s;
            }
        }
        return s;
    }
};