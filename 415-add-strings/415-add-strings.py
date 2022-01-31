"""""
1. If we subtract ‘0’ a character number, then we’ll get the integer value of that number.
2. For example, the ASCII value of ‘0’ is 48 and ‘9’ is 57, so if we do ‘9’-’0’= 57-48 = 9.
3. So using this logic we’ll iterate bot array elements from last and subtract ‘0’ from them.
4. Add that value to sum, which also count the carry.
5. Push the ans as mod of sum, cz it will give the last element from sum.
6. Ans after that divide sum with 10, which will store the carry.
7. Finally, reverse the array, cz we pushed the last element first.
8. Time complexity: O(n + m) / size of the arrays.
"""""

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        
        a = len(num1) - 1
        b = len(num2) - 1
        
        output = ""
        carry = 0
        
        while a >= 0 or b >= 0:
            i, j = 0, 0
            
            if a >= 0:
                i = ord(num1[a]) - ord('0')
                a -= 1
            
            if b >= 0:
                j = ord(num2[b]) - ord('0')
                b -= 1
                
            temp = i + j + carry
            
            if temp > 9:
                carry = 1
            else:
                carry = 0
                
            output = str(temp)[-1] + output
        
        if carry:
            output = "1" + output
        return output
                
        
        