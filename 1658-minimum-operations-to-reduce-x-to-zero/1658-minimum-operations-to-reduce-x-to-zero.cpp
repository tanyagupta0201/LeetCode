class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mymap; //<sum,pos>
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            mymap[sum] = i;
        }
        if (x > sum) // Sum out of range
            return -1;
        mymap[0] = 0;

        int longest = 0;
        sum -= x;
        int val = 0;
        for (int i = 0; i < n; ++i)
        {
            val += nums[i];
            if (mymap.count(val - sum))
            {
                if (val - sum == 0)
                    longest = max(longest, i - mymap[val - sum] + 1);
                else
                    longest = max(longest, i - mymap[val - sum]);
            }
        }
        return longest == 0 ? (sum == 0 ? n : -1) : n - longest;
    }
};