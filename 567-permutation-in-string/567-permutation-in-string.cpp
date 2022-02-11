class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        
        if(s1.size() > s2.size())
            return false;

        int left = 0, right = 0;
        
        while(right < s1.size())
        {
            m1[s1[right] - 'a'] += 1;
            m2[s2[right] - 'a'] += 1;
            right += 1;
        }
        
        right -= 1; // to point right to the end of the window
        
        while(right < s2.size())
        {
            if(m1 == m2)
                return true;
        
            right += 1;
            
            if(right != s2.size())
            {
                m2[s2[right] - 'a'] += 1;
            }
            
            m2[s2[left] - 'a'] -= 1;
            left += 1;
        }
 
        return false;        
    }
};