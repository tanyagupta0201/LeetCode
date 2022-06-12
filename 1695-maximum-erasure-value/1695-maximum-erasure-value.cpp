class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size(), i = 0, sum = 0, temp = 0;
        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++)
        {
            if (mp.find(nums[j]) == mp.end())
                mp[nums[j]] = j;
            else
            {
                while (i <= mp[nums[j]])
                {
                    temp -= nums[i];
                    i++;
                }
                mp[nums[j]] = j;
            }
            temp += nums[j];
            sum = max(sum, temp);
        }
        return sum;
    }
};