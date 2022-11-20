class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;

        unordered_set<float> s;

        while (i < j)
            s.insert((nums[i++] + nums[j--]) / 2.0);

        return s.size();
    }
};