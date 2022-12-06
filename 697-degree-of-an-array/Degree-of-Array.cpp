class Solution
{
public:
    // We want the min length of the subarray that includes the element which has highest degree(highest freq)
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> first; // stores the first occurence of an element
        unordered_map<int, int> last;  // stores the last occurence of an element
        unordered_map<int, int> freq;  // stores the freq of element

        for (int i = 0; i < nums.size(); i++)
        {
            if (first.count(nums[i]) == 0)
                first[nums[i]] = i;

            last[nums[i]] = i;

            freq[nums[i]]++;
        }

        int maxi = 0;
        for (auto it : freq)
        {
            maxi = max(it.second, maxi);
        }

        int ans = nums.size();
        for (auto it : freq)
        {
            if (it.second == maxi)
            {
                ans = min(ans, last[it.first] - first[it.first] + 1);
            }
        }

        return ans;
    }
};