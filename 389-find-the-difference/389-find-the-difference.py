# https://youtu.be/sRwElQ_TOr8

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        c = 0
        
        for i in s:
            c = c ^ ord(i)
        
        for j in t:
            c = c ^ ord(j)
        
        return chr(c)