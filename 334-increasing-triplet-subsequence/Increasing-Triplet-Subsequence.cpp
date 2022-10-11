class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();

        // if number of elements are less than 3 then not possible
        if (n < 3)
            return false;

        // 2 pointer approach
        int low = INT_MAX;
        int mid = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > mid)
            {
                // triplet found
                return true;
            }
            else if (nums[i] > low && nums[i] < mid)
            {
                mid = nums[i];
            }
            else if (nums[i] < low)
            {
                low = nums[i];
            }
        }

        return false;
    }
};