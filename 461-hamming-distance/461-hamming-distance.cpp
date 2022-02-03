class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int result = x ^ y;
        return __builtin_popcount(result);        
    }
};