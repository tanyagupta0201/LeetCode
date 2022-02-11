// https://youtu.be/0I6IL3TnIZs

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> m;
        
        string temp;
        int n = strs.size();
        
        for(int i = 0; i < n; i++)
        {
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(temp);            
        }
        
        vector<vector<string>> res;
        
        for(auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};