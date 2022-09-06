class Solution {
public:
    int minSteps(string s, string t) 
    {
        int ans = 0;
        
        int freq[26] = {0};
        
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for(auto i : freq)
        {
            if(i > 0)
               ans += i;
        }
        
        return ans;
    }
};