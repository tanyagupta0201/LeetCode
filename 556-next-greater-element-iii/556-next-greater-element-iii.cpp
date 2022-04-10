class Solution {
public:
    int nextGreaterElement(int n)
    {
        string limit = "2147483647"; // Answer cannot be greater than 2^31 - 1
        
        string num = to_string(n);   // Convert n into string
        
        next_permutation(num.begin(), num.end()); // Find the next greater permutation
        
        // Check next greater is larger than limit
        if(num.size() == 10 && num > limit)
            return -1;
        
        int ans = stoi(num); // Convert number to integer
        
        // Check it is less than or equal to n
        if(ans <= n)
            return -1;
        else
            return ans;
            
    }
};

/* 

What is the use of num.size() == 10 ?

because comparing between two strings is lil bit different than comparing two int numbers.
say staring a="31", b= "113", here clearly number presented by string b, 113 is greater than number presented by string a, 31, but if we compare string a and b, it will tell us number a is greater than b. The reason is, string comparison doesn't check the length, it compare from the very beginning i.e first it will compare a[0] and b[0], 3 and 1 and 3>1 so return a as greater string. So, to avoid such case, in this problem, we just have to check if our number is greater than limit, that means it can happen only if number contains 10 digits because limit itself contains 10 digit, so any number having less than 10 digits cannt be larger than limit and we dont need to check it.

*/