// https://leetcode.com/problems/split-array-largest-sum/discuss/1899223/100-oror-C%2B%2B-oror-Binary-Search-oror-Easy-to-Understand-oror-Simple-Logic

class Solution {
  public:
    bool check(vector < int > & nums, int m, int curr) 
    {
      int i = -1, n = nums.size(), count = 1;

      int sum = 0;

      while (++i < n && count <= m) 
      {
        // if adding the nums[i] does not make the sum greater than curr (mid), we add it to group
        if (sum + nums[i] <= curr)
          sum += nums[i];

        // else we can add a new group to store the remaining element.
        else sum = nums[i], count++;
      }

      // If the total number of groups is less than the m, we can split the any of the current group of size >= 2.
      // this will not increase the maximum sum and hence our answer will still be valid

      return count <= m;
    }

  int splitArray(vector < int > & nums, int m) 
  {
    int e = 0, s = 0, mid, ans;
      
    for (auto x: nums) 
    {
      e += x; // e stores the sum of the nums, upper range of Binary Search
      s = max(s, x); // s stores the largest element in array nums, lower range of Binary Search
    }
      
    ans = e;

    while (s <= e) 
    {
      mid = s + (e - s) / 2;

      if (check(nums, m, mid)) 
      {
        ans = min(ans, mid);
        e = mid - 1;
      } 
      else
        s = mid + 1;
    }
    return ans;
  }
};