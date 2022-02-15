class Solution {
public:
    bool isSameAfterReversals(int num)
    {
        int original = num;
        int temp = num;
        
        int rev1 = 0, rev2 = 0, rem1, rem2;
        
        while(temp > 0)
        {
            rem1 = temp % 10;
            rev1 = rev1 * 10 + rem1;
            temp /= 10;
        }
        
        while(rev1 > 0)
        {
            rem2 = rev1 % 10;
            rev2 = rev2 * 10 + rem2;
            rev1 /= 10; 
        }
        
        if(rev2 == original)
            return true;
        return false;
        
    }
};