class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> ans;
        map<int, int> mp;
        
        for(auto x : arr1)
        {
            mp[x]++;
        }
        
        for(auto temp : arr2)
        {          
            if(mp.find(temp) != mp.end())
            {
                auto ele = mp.find(temp);
                int freq = ele->second;
                
                vector<int> v(freq, temp); // eg: 6->3
                ans.insert(ans.end(), v.begin(), v.end());
                mp.erase(temp);
            }
        }
        
        // Remaining elements that were not present in arr2 but present in arr1
        for(auto x: mp)
        {
            int ele = x.first;
            int freq = x.second;
            
            vector<int> v(freq, ele);
            ans.insert(ans.end(), v.begin(), v.end());          
        }
        
        return ans;
    }
};