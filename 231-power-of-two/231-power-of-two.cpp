class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        int ans = 0;
        
        while(n > 0)
        {
            n = n & (n - 1);
            ans++;
        }
        
        if(ans == 1)
            return true;
        return false;
    }
};