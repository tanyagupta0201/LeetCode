class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        currS = ''
        currN = 0
        
        for ch in s:
            if ch == '[':
                stack.append(currS)
                stack.append(currN)
                currS = ''
                currN = 0
                
            elif ch == ']':
                prevN = stack.pop()
                prevS = stack.pop()
                currS = prevS + prevN * currS
                
            elif ch.isdigit():
                currN = currN * 10 + int(ch)
                
            else:
                currS += ch
                
        return currS