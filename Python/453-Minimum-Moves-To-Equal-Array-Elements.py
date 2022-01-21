# Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

# increasing all n-1 element except the largest one is similar to decreasing the largest element only.
# So, the smallest elements need not to decrease any more and rest of elements will got decremented upto smallest one.
# In this way the total number of operation required for making all elements equal will be arraySum – n * (smallestElement).

class Solution:
    def minMoves(self, nums: List[int]) -> int:

        n = len(nums)

        minMoves = sum(nums) - (min(nums) * n)

        return minMoves
