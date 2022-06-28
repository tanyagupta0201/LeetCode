// explanation: https://www.youtube.com/watch?v=8q0xs_5u22E

class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> freq(26);
        
        for(auto it: s)
        {
            freq[it - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>()); // sort in descending
        
        int maxFreq = freq[0];
        int ans = 0;
        
        for(auto currFreq: freq)
        {
            if(currFreq > maxFreq)
            {
                if(maxFreq > 0)
                {
                    ans += (currFreq - maxFreq);
                }
                else
                {
                    ans += currFreq;
                }
            }
            
            maxFreq = min(currFreq - 1, maxFreq - 1);
        }
        
        return ans;
    }
};