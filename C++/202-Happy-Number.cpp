// Problem Link: https://leetcode.com/problems/happy-number/

// Method 1

class Solution
{
public:
    bool isHappy(int n)
    {

        if (n == 1 || n == 7)
            return true;

        int sum = n, x = n;

        while (sum > 9)
        {
            sum = 0;

            while (x > 0)
            {
                int rem = x % 10;
                sum = sum + (rem * rem);
                x /= 10;
            }

            if (sum == 1)
                return true;

            x = sum;
        }
        if (sum == 7)
            return true;

        return false;
    }
};

// Method 2

// We can use sets as it stores only unique values
// Simply store every value we got in the sum
// if the value is found again that means it is forming a loop and this loop will never end
// So the number cannot be happy number.

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = 0, rem;
        set<int> s;

        while (1)
        {
            sum = 0;

            while (n)
            {
                rem = n % 10;
                sum += rem * rem;
                n = n / 10;
            }

            if (sum == 1 || sum == 7)
                return true;
            else if (s.find(sum) != s.end())
                return false;

            s.insert(sum);
            n = sum;
        }
        return false;
    }
};
