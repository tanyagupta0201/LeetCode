class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans;
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq[nums[i]] == 2)
            {
                ans.push_back(nums[i]);
                break;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (freq[i] == 0 && i != 0)
            {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};