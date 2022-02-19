// https://youtu.be/M7VmwWAnpUE

class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        set<int> s;
        
        for(auto n : nums)
        {
            if(n % 2 == 1) // odd number
                s.insert(n * 2); // Perform the odd operation
            else
                s.insert(n); // simply add the number
        }
        
        int deviation = INT_MAX; // As we want minimum deviation
        
        while(true)
        {
            int max_val = *s.rbegin();
            
            deviation = min(deviation, max_val - *s.begin());
            
            // when max val becomea odd we need to terminate the loop, as for odd we need to multiply
            if(max_val % 2 == 1)
            {
                break;
            }
            else
            {
                // Remove the max element and perform the even operation
                s.erase(max_val);
                s.insert(max_val / 2);
            }
        }
        return deviation;
    }
};