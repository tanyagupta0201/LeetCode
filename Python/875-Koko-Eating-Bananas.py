# Problem Link: https://leetcode.com/problems/koko-eating-bananas/

# YouTube Link: https://youtu.be/LzZFUTWE55c

# Binary Search

class Solution:
    def isPossible(self, piles: List[int], h: int, sp: int):
        time = 0
        for i in piles:
            time += math.ceil(i * 1.0 / sp)

        if time <= h:
            return True
        else:
            return False

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = max(piles)
        speed = 0

        if(high == len(piles)):
            return high

        while low <= high:
            sp = low + (high - low) // 2

            if self.isPossible(piles, h, sp) == True:
                speed = sp
                high = sp - 1
            else:
                low = sp + 1

        return speed
