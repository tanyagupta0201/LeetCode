
// Solution 1
class Solution
{
public:
    // TC = O(N), SC = O(1)
    int mySqrt(int x)
    {
        long long int i = 1;

        while (i * i <= x)
        {
            i++;
        }

        return (i - 1);
    }
};

// Solution 2
class Solution
{
public:
    // Binary Search
    // TC = O(Log N), SC = O(1)
    int mySqrt(int x)
    {
        long long int low = 1, high = x, ans = 0;

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;

            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};