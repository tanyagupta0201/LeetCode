# https://youtu.be/9XQxIvdqIt0
# wahi bulbs on rahenge jinke factors odd honge
# sabke even number of factors aate hain except perfect square
# taking only integer part

class Solution:
    def bulbSwitch(self, n: int) -> int:
        bulbs = int(math.sqrt(n))
    
        return bulbs