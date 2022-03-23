/*

class Solution {
public:
    // Recursive Approach
    int brokenCalc(int startValue, int target) 
    {
        if(startValue >= target)
            return startValue - target;
        
        // We will try to half the target, so that we reach the startValue early
        if(target % 2 == 0)
        {
            return 1 + brokenCalc(startValue, target / 2);
        }
        else
        {
            return 1 + brokenCalc(startValue, target + 1);
        }
        
    }
};

*/



class Solution {
public:
    // Iterative Approach
    int brokenCalc(int startValue, int target) 
    {
        int steps = 0;
        
        while(target > startValue)
        {
            steps++;
            
            if(target % 2 == 0)
            {
                target /= 2;                
            }
            else
            {
                target += 1;
            }
        }
        
        return steps + (startValue - target);
    }
};