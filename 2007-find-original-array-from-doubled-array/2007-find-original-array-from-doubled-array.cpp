class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        int n = changed.size();
        
        // if the size is odd, it is not possible to get double array
        if(n % 2 == 1)
            return {};
        
        vector<int> ans;
        unordered_map<int, int> mp;
        
        /*
           for eg ...if we had not done sorting {2,1}
           toh iss case me map me 2 ka double ni hai ...so we return empty array.....but we should have sorted it so it becomes {1,2}            so 1 ka double present hai ....so original array becomes {1}
        */
        sort(changed.begin(), changed.end());
        
        for(auto it : changed)
        {
            mp[it]++;
        }
        
        for(int it : changed)
        {
            if(mp[it] == 0) // it has already occured 
                continue;
            
            if(mp[2 * it] == 0) // double value of the current value does not exists 
                return {};
            
            if(mp[it] && mp[it * 2]) // both exist
            {
                ans.push_back(it);
                mp[it]--;
                mp[2 * it]--;
            }                
        }
        
        return ans;
    }
};