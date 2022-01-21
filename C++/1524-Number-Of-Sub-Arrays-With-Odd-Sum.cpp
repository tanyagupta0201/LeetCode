#Problem Link : https: // leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int ans = 0, mod = 1e9 + 7;
        int even = 0, odd = 0;
        int sum = 0;

        for (int i : arr)
        {
            sum += i;

            if (sum % 2 == 0)
            {
                ans = (ans + odd) % mod;
                even++;
            }
            else
            {
                ans = (ans + 1 + even) % mod;
                odd++;
            }
        }
        return ans;
    }
};