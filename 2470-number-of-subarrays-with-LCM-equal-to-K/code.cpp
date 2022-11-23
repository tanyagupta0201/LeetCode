class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int LCM = nums[i];

            for (int j = i; j < nums.size(); j++)
            {
                LCM = lcm(LCM, nums[j]);

                if (LCM == k)
                {
                    count++;
                }

                if (LCM > k) // aage kitne bhi number aaye LCM ya toh itna hi rahega warna increase hi hoga
                {
                    break;
                }
            }
        }

        return count;
    }
};