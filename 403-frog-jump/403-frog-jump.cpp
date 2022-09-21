class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        
        map<int, set<int>> mp;
        set<int> st;
        
        for (auto it : stones)
            mp[it] = st;
        
        mp[stones[0]].insert(1); // jump from 0 is always possible
        
        for (int i = 0; i < n; i++)
        {
            int currStone = stones[i];
            set<int> jumps = mp[currStone];
        
            for (auto jump : jumps)
            {
                int pos = currStone + jump;
                
                // if the frog has reached last position, return true
                if (pos == stones[n - 1])
                    return true;
                
                if (mp.find(pos) != mp.end())
                {
                    // insert all the suitable positions
                    if (jump - 1 > 0)
                    {
                        mp[pos].insert(jump - 1);
                    }
                    
                    mp[pos].insert(jump);
                    mp[pos].insert(jump + 1);
                }
            }
        }
        
        return false;
    }
};