/*
The idea is simple; you have a base of 3 prime numbers conveniently stored in primes, you loop through them, progressively reducing the initially provided number, if and only as long each of the primes is a divisor of it.

At the end of the run, if what you are left with is == 1, then you had an ugly number, false otherwise (and note that it would also rule out non-positive numbers, but I prefer to just save computation and check initially for it).

Incidentally, the order by which the algorithm checks the primes is irrelevant, but I preferred to keep them in increasing order.
*/

class Solution {
public:
    bool isUgly(int n) 
    {
        // negative number
        if(n < 1)
           return false;
        
        vector<int> divisors = {2, 3, 5};
        
        for(int i : divisors)
        {
            while(n % i == 0)
                n = n / i;   
        }
        
        return n == 1;
    }
};