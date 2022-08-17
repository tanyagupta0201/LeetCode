
/*

NORMAL SORTING

TC = O(NLOGN)
SC = O(1)

class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        vector<int> diff(n - 1);
        
        for(int i = 1; i < n; i++)
        {
            diff.push_back(nums[i] - nums[i - 1]);
        }
        
        return *max_element(diff.begin(), diff.end());
    }
};

*/

// Bucket Sort & PigeonHole Technique
// Explanation:
// https://leetcode.com/problems/maximum-gap/discuss/1251483/C%2B%2B-andandO(N)-Bucket-sort-and-pigeon-hole-with-detail-explanation.one-of-the-very-nice-approach
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        // find the max and min element
        int mx = nums[0], mn = nums[0];
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        int avg = max((mx - mn) / (n - 1), 1);
        int size = (mx - mn) / avg + 1; // number of buckets

        int mnA[size], mxA[size];

        for (int i = 0; i < size; i++)
            mnA[i] = INT_MAX, mxA[i] = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int pos = (nums[i] - mn) / avg; // index of bucket

            // puting elements in their buckets
            // every number is put into both the arrays
            // if there is more than 1 element on the same index then bucketMin will take the smallest element among them and bucketMax will take greatest element among them
            mnA[pos] = min(mnA[pos], nums[i]);
            mxA[pos] = max(mxA[pos], nums[i]);
        }

        int ans = 0;
        int i = 0, j = 1;

        while (i < size - 1 && j < size)
        {
            if (mnA[j] == INT_MAX)
            {
                j++;
                continue;
            }
            //  Ignoring this bucket since there is no element present
            if (mxA[i] == INT_MIN)
            {
                i++;
                continue;
            }

            ans = max(ans, mnA[j] - mxA[i]);
            i++;
            j++;
        }

        return ans;
    }
};