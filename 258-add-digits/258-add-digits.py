class Solution:
    def addDigits(self, num: int) -> int:
        while len(str(num)) != 1:
            a = str(num)
            num = 0
            
            for i in a:
                num = num + int(i)
                
        return num
    
    
# The original number is divisible by 9 if and only if the sum of its digits is divisible by 9
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9
