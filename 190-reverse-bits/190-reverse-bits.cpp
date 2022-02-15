// https://youtu.be/LJiMk8lPJNc

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        int res = 0;
        
        for(int i = 0; i < 32; i++)
        {
            int lsb = n & 1;
            int reverse_lsb = lsb << (31 - i);
            
            // fixing the reverse_lsb
            res = res | reverse_lsb;
            
            n = n >> 1;
        }
        return res;
    }
};