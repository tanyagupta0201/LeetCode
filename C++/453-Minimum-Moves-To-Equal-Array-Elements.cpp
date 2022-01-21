// Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minimum = INT_MAX;
        int n = nums.size();
        int sum = 0;

        for (int i : nums)
        {
            minimum = min(minimum, i);
            sum += i;
        }

        return sum - minimum * n;
    }
};