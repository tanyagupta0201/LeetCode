// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/1871662/JavaC%2B%2B-Easiest-Possible-Exaplained!!

class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string res(n,'a');
        k -= n;
        
        while(k > 0){
            res[--n] += min(25, k);
            k -= min(25, k);
        }
        return res;
    }
};