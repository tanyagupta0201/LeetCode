class Solution
{
public:
    int reverse(int n)
    {
        int rev = 0;
        while (n)
        {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n = n / 10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int> &nums)
    {
        int n = nums.size();
        set<int> s;

        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }

        return s.size();
    }
};