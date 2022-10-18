class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto it : nums)
            mp[it]++;

        int maxi = INT_MIN, flag = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                if (mp.find(0 - nums[i]) != mp.end())
                {
                    maxi = max(maxi, nums[i]);
                    flag = 1;
                }
            }
        }

        if (flag == 1)
            return maxi;

        return -1;
    }
};