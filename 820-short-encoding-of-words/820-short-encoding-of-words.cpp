// https://www.youtube.com/watch?v=6f0pLQYG834

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        int n = words.size();
        
        unordered_set<string> se(words.begin(), words.end());
        
        for(auto &s : se)
        {
            int m = s.size();
            
            for(int i = 1; i < m ; i++)
            {
                string str = s.substr(i, m);
                
                if(se.find(str) != se.end())
                {
                    se.erase(str);
                }
            } 
        }
        
        int ans = 0;
        for(auto &s : se)
        {
            ans += s.size() + 1; // 1 is added for #
        }
        
        return ans;
    }
};