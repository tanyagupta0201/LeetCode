class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        if(n == 1 && k == 1)
            return 0;
        
        int mid = pow(2, n - 1) / 2;
        
        // values before mid are mapped directly to kth value in the (n - 1) row
        if(k <= mid)
        {
            return kthGrammar(n - 1, k);
        }
        // values after mid are mapped directly to kth value in the (n - 1) row and is complement of the value
        else
        {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};