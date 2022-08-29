class comp {
    public:
    bool operator() (pair<int, string> &p1, pair<int, string> &p2)
    {
        if(p1.first != p2.first)
        {
           return p1.first > p2.first;
        }
        
        return p1.second < p2.second;
    }   
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        int n = words.size();
        unordered_map<string, int> mp;
        
        for(auto it : words)
            mp[it]++;
        
        // Take min heap as we want to remove the words with lesser freq
        // with the help of min heap they would be removed as they would come up on the top
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->second, it->first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans(k);
        
        while(!pq.empty())
        {
            ans[k - 1] = pq.top().second;
            pq.pop();
            k--;
        }
        
       // sort(ans.begin(), ans.end());
        return ans;
        
    }
};