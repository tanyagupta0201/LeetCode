# Problem Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9+7
        s = 0
        odd = 0
        even = 0
        ans = 0

        for i in arr:
            s += i
            if s % 2 == 0:
                ans = (ans + odd) % mod
                even += 1
            else:
                ans = (ans + 1 + even) % mod
                odd += 1

        return ans
