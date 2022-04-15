class Solution {
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        
        for(int d = 5; n / d >= 1; d = d * 5)
        {
            ans += n / d;
        }
        
        return ans;
    }
};