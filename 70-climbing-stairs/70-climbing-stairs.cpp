// https://youtu.be/AWezsCJDHSk
// This ques is just like fibonacci number, we need the answer of the previous 2 terms
class Solution {
public:
    int climbStairs(int n) 
    {
        if (n <= 2)
            return n;
        
        int x = 1, y = 2;
        
        for(int i = 3; i < n; i++)
        {
            int temp = y;
            y = y + x;
            x = temp;
        }

        return x + y;        
    }
};