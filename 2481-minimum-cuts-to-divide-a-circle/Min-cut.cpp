class Solution
{
public:
    int numberOfCuts(int n)
    {
        // edge case
        if (n == 1)
            return 0;

        // for even
        if (n % 2 == 0)
            return n / 2;

        // for odd
        return n;
    }
};