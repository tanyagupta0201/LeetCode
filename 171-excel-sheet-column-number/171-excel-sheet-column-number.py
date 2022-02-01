class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        n = len(columnTitle)
        
        p = 0
        ans = 0
        
        for i in range(n - 1, -1, -1): # Reversed Loop
            val = ord(columnTitle[i]) - ord('A') + 1 # Calculating the value (A = 1, B = 2,...)
            ans += val * pow(26, p)
            p += 1
        
        return ans
        
        