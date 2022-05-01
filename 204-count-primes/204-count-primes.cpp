class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> arr(n + 1, 1); // mark all the numbers as prime numbers
        arr[0] = arr[1] = 0; // we know 0 and 1 are not prime numbers
        
        // Sieve of Eratosthenes
        for(int i = 2; i * i <= n; i++)
        {
            if(arr[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    arr[j] = 0;                    
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i])
            {
                count++;
            }
        }
        
        return count;        
    }
};