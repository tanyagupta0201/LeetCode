class Solution {
public:
    /*
    Left shift of negative value is not allowed in C and C++
    
In 32-bit case, if the highest bit of carry is 1, than the overflow will happen after applying <<. However, in 64-bit, when 1 occurs at the 33th bits is ok, then (carry & 0xffffffff) << 1 will clear those 1s higher than 32th bits while don't influence the other 1s, and it avoid overflow. (0xffffffff = 0000 0000 0000 0000 0000 0000 0000 0000 1111 1111 1111 1111 1111 1111 1111 1111) it is equal to -1.
    
    */
    int getSum(int a, int b) 
    {
        int sum = a;
        int carry = b;
        
        while(carry != 0)
        {
            sum = a ^ b;
            
            // carry is added for next number so we have to left shift it
            carry = ((a & b) & 0xffffffff) << 1; // limited to 32 bits
            
            
            a = sum;
            b = carry;
        }
        
        return sum;        
    }
};