// https://leetcode.com/problems/mirror-reflection/discuss/2376191/C%2B%2B-Java-Python-or-Faster-then-100-or-Full-explanations-or

class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        while (p % 2 == 0 && q % 2 == 0)
        { 
            p /= 2;
            q /= 2;
        }
        
        return 1 - p % 2 + q % 2;
    }
};