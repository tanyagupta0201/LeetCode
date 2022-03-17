class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> Original_map;
        
        for(auto it: s)
        {
            Original_map[it]++;
        }
        
        map<int, string, greater<int>> new_map;
        
        for(auto it: Original_map)
        {
            new_map[it.second].push_back(it.first);
        }
        
        string ans = "";
        for(auto it : new_map)
        {
            for(int j = 0; j < it.second.size(); j++)
            {
                int cnt = it.first;
                
                while(cnt--)
                {
                    ans += it.second[j];
                }
            }
        }
        
        return ans;
    }
};