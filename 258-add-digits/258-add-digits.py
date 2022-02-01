class Solution:
    def addDigits(self, num: int) -> int:
        while len(str(num)) != 1:
            a = str(num)
            num = 0
            
            for i in a:
                num = num + int(i)
                
        return num