class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        // starting from end because we want largest perimeter
        for (int i = nums.size() - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        // not possible
        return 0;
    }
};