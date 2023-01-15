class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int eleSum = 0, digitSum = 0;

        for (auto it : nums)
        {
            eleSum += it;
        }

        for (auto it : nums)
        {
            int n = it;
            while (n > 0)
            {
                digitSum += n % 10;
                n = n / 10;
            }
        }

        return abs(digitSum - eleSum);
    }
};