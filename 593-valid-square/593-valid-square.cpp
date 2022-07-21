class Solution {
public:
    int dis(vector<int> &a, vector<int> &b)
    {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        
        return x * x + y * y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        // only 6 possible distances 
        vector<int> sides = {dis(p1, p2), dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)};
        
        unordered_map<int, int> mp; // {side length, count}
        
        for(auto &it: sides)
        {
            mp[it]++;
        }
        
        // the size of the map should be 2 only
        // for being square, all sides should be equal and both diagonals must be equal
        // so one value(count) should be equal to 4 and another 2
        
        if(mp.size() != 2)
            return false;
        
        // no side can be zero
        for(auto &it: mp)
        {
            if(it.first == 0)
                return false;
        }
        
        for(auto &it: mp)
        {
            return (it.second == 2) || (it.second == 4);
        }
        
        return false;
    }
};