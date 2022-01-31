class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == '' and t == '':
            return True
        
        p = 0 # pointer for s
        q = 0 # pointer for t
        
        for i in range(len(t)):
            
            if p == len(s):
                return True
            
            if s[p] == t[i]:
                p += 1
                
        if p == len(s):
            return True
        return False
            
        
            
        