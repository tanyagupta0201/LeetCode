class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto it: nums)
        {
             s.insert(it);       
        }
        
        int longestStreak = 0, currStreak = 0, currNum;
        
        for(auto it: nums)
        {
            if(!s.count(it - 1))
            {
                currNum = it;
                currStreak = 1;
                
                while(s.count(currNum + 1))
                {
                    currNum++;
                    currStreak++;
                }
                
                longestStreak = max(currStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};