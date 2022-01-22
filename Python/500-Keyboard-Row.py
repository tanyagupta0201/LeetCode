# Problem Link: https://leetcode.com/problems/keyboard-row/

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        s1, s2, s3 = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')
        output = []

        for i in words:
            j = set(i.lower())

            if j.issubset(s1) or j.issubset(s2) or j.issubset(s3):
                output.append(i)

        return output
