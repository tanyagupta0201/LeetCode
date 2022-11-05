// TC = SC = O(1)

class Solution
{
public:
    int minOperations(int n)
    {
        int mid = n / 2;

        if (n & 1) // n is odd
        {
            return mid * (mid + 1);
        }

        // n is even
        return mid * mid;
    }
};