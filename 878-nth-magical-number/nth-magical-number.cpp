class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        long mod = (long)1e9 + 7;

        long low = min(a, b);
        long high = (long)n * min(a, b);

        long LCM = (a * b) / __gcd(a, b);

        while (low < high)
        {
            long mid = low + (high - low) / 2;

            // count number of magical numbers till mid
            // there will be some number that would be common so we need to subtract them once as they are counted twice
            long count = (mid / a) + (mid / b) - (mid / LCM);

            if (count < n)
            {
                // since there are less than n magical numbers we need to increase our range
                low = mid + 1; // kyuki mid tak toh calculate karliya tha
            }
            else if (count >= n)
            {
                // there more than n magical numbers so we need to lower our range
                high = mid;
            }
        }
        return (int)(high % mod);
    }
};