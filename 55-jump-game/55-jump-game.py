# https://youtu.be/muDPTDrpS28

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reachable = 0
        
        for i in range(n):
            if reachable < i:
                return False
            reachable = max(reachable, i + nums[i])
        return True