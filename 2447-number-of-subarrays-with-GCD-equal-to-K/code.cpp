class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int GCD = nums[i];

            for (int j = i; j < nums.size(); j++)
            {
                GCD = __gcd(GCD, nums[j]);

                if (GCD == k)
                {
                    count++;
                }

                if (GCD < k) // aage kitne bhi number aaye k se toh smaller hi rahega
                {
                    break;
                }
            }
        }

        return count;
    }
};