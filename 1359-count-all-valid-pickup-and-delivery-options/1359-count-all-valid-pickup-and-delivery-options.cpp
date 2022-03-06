// Explanation: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1823403/C%2B%2B-oror-Easy-To-Understand-oror-Full-Explanation-oror-Coimbanotrics

class Solution {
public:
    int countOrders(int n) 
    {
        long res = 1, mod = 1000000007;
        
        for(int i = 1; i <=n; ++i)
        {
			// calulating n!
            res *= i;
            
			// to avoid overflow
            res %= mod;
			
			// (2*i-1) are the vacant places which we can choose
			// later we have n! permutation of pickup task
			// therefore we have to multiply with n! that we calculated as res.
            res *= (2*i-1);
			
			// to avoid overflow
            res %= mod;
        }
        
		// to avoid overflow
        return res % mod;
    }
};