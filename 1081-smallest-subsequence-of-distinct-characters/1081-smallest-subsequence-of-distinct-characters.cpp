class Solution {
public:
    string smallestSubsequence(string s) 
    {
        vector<int> freq(26);
        vector<int> vis(26);
        
        string res = "";
        
        for(auto it : s)
            freq[it - 'a']++;
        
        for(auto it : s)
        {
            freq[it - 'a']--;
            
            // If the character is not visited already
            if(!vis[it - 'a'])
            {
                // Since we need to return ans in smallest lexicographic order
                while(!res.empty() && res.back() > it && freq[res.back() - 'a'] > 0)
                {
                    vis[res.back() - 'a'] = false;
                    res.pop_back();
                }
                
                vis[it - 'a'] = true;
                res += it;
            }
                
        }
        
        return res;
    }
};