class Solution {
public:
    string reorganizeString(string s)
    {
        string ans;
        
        unordered_map<char,int> mp;
        for(auto i : s) mp[i]++;
        
        if(mp.size() < 2) 
            return ans;
        
        priority_queue<pair<int,char>> pq;
        for(auto i : mp) 
            pq.push({i.second, i.first});
        
        while(pq.size() > 1)
        {
            char s1 = pq.top().second;
            int count1 = pq.top().first;
            ans.push_back(s1);
            count1--;
            pq.pop();
            
            char s2 = pq.top().second;
            int count2 = pq.top().first;
            ans.push_back(s2);
            count2--;
            pq.pop();
            
            if(count1 > 0)
                pq.push({count1,s1});
            
            if(count2 > 0)
                pq.push({count2,s2});
        }
        
        if(!pq.empty() and pq.top().first > 1) 
            ans.clear();
        else if(!pq.empty() and pq.top().first == 1)
            ans += pq.top().second;
        
        return ans;
    }
};