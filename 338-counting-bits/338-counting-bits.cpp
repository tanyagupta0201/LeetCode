class Solution {
public:
    int CountBitsFast(int n)
    {
        int bits = 0;
        
        while (n > 0)
        {
            n = n & (n - 1);
            bits++;
        }
        
        return bits;
    }
    
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        
        for(int i = 0; i <= n; i++)
        {
            int setBits = CountBitsFast(i);
            ans.push_back(setBits);
        }
        
        return ans;
    }
};