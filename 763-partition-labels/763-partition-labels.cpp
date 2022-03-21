class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> last_index(26, 0); // last index of each character
        for(int i = 0; i < s.length(); i++)
        {
            last_index[s[i] - 'a'] = i;
        }
        
        vector<int> ans;
        int start = 0, end = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            end = max(end, last_index[s[i] - 'a']);
            
            if(i == end)
            {
                // all the characters of the given partition are included
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};