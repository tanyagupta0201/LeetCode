class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        for i in nums:
            return len(set(nums)) != len(nums) # means it has duplicates
            
            