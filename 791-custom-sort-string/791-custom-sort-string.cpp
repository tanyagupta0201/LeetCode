class Solution {
public:
    string customSortString(string order, string s) 
    {
        map<char, int> mp;
        string ans = "";
        
        for(auto x : s)
            mp[x]++;
        
        for(auto x : order)
        {
            if(mp.find(x) != mp.end())
            {
                auto ele = mp.find(x);
                int freq = ele->second;
                
                string str(freq, x);
                ans += str;
                mp.erase(x);
            }
        }
        
        for(auto x : mp)
        {
            string str(x.second, x.first);
            ans += str;
        }
        
        return ans;
    }
};