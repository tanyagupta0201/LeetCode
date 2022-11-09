// https://youtu.be/AWJndqifK8s

// we will be searching from unit place and find the non -ve number
// now we will try to convert this non -ve number into zero
// if any number has 0 then its summation will be minimum
// cnt = 10, 100, 1000, ....
// after that add the difference to n, ie. it is the number that we need to add so that number becomes zero

class Solution
{
public:
    long long sumOfDigits(long long n)
    {
        long long sum = 0, rem = 0;

        while (n)
        {
            rem = n % 10;
            sum += rem;
            n = n / 10;
        }

        return sum;
    }

    long long makeIntegerBeautiful(long long n, int target)
    {
        if (sumOfDigits(n) <= target)
            return 0;

        long long temp = n;
        long long cnt = 10;
        // long long n1 = n, n2 = n;

        while (sumOfDigits(temp) > target)
        {
            long long mod = n % cnt; // we have to find the non-zero integer from unit place
            temp = n + (cnt - mod);  // new integer which will be beautiful
            cnt *= 10;
        }

        return temp - n; // difference
    }
};