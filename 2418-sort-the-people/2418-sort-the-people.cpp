class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        map<int, string> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp.insert({heights[i], names[i]});
        }
        
        vector<string> ans(n);
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans[n - 1] = it->second;
            n--;
        }
        
        return ans;        
    }
};