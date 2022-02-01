class Solution {
public:
    int FindSum(int n)
    {
        int sum = 0;
        
        while(n > 0)
        {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    
    int addDigits(int num)
    {
        int sum = num;
        
        while(num > 0)
        {
            // Previous sum value is passed to find sum of digits
            sum = FindSum(sum); 
            
            if(sum / 10 <= 0)
                break;
        }
        return sum;
    }
};