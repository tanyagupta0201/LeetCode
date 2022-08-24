class Solution {
public:
    // We can keep dividing a number till it is divisible by 3. At last, if the number is equal to 1, return true, otherwise return false. We need to handle

    bool isPowerOfThree(int n)
    {
        if(n <= 0)
           return false;
        
        while(n % 3 == 0)
        {
            n = n / 3;
        }
        
        if(n == 1)
            return true;
        
        return false;
    }
};