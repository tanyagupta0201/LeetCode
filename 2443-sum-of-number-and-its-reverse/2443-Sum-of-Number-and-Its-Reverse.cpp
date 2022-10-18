/*
Simple Bruteforce approach, consider each number from 0 to n and
check if its reverse add it to give the value of n or not.
*/

class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            int n = i;
            int rev = 0;

            while (n > 0)
            {
                int rem = n % 10;
                rev = rev * 10 + rem;
                n = n / 10;
            }

            if (i + rev == num)
                return true;
        }
        return false;
    }
};
