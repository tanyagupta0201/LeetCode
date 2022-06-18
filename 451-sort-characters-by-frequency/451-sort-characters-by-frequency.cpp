class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> mp;
        string ans = "";
        int n = s.size();
        
        for(auto it: s)
            mp[it]++;
        
        priority_queue<pair<int, char>> pq; // {freq, char}
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->second, it->first});
        }
        
        while(pq.size() > 0)
        {
            int k = pq.top().first;
            
            while( k > 0)
            {
               ans += pq.top().second;
               k--;
            }
            
            pq.pop();
        }
        
        return ans;        
    }
};