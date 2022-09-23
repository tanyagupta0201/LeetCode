// https://youtu.be/yMwSJfpSYEo

class Solution {
public:
    int concatenatedBinary(int n) 
    {
        long ans = 0, mod = 1e9+7, length = 0;
        
        for (int i = 1; i <= n; ++i)
        { 
            if ((i & (i - 1)) == 0)
                length++;
            
            ans = ((ans << length) + i) % mod;
        }
        
        return ans;
    }
};