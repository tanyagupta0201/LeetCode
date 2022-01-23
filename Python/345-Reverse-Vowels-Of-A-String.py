# Problem Link: https://leetcode.com/problems/reverse-vowels-of-a-string/


class Solution:
    def reverseVowels(self, s: str) -> str:
        v = "aeiouAEIOU"
        low = 0
        high = len(s) - 1
        s = list(s)

        while low < high:
            if not s[high] in v:
                high -= 1
            elif not s[low] in v:
                low += 1
            else:
                s[low], s[high] = s[high], s[low]
                low += 1
                high -= 1

        return ''.join(s)
