class Solution {
public:
    int reverse(int x) 
    {
        string s = to_string(x);
        
        // Remove the negative sign
        if(x < 0)
        {
            s = s.substr(1);
        }
        
        char temp;
        int n = s.size();
        
        // Reverse the string
        for(int i = 0; i < n / 2; i++)
        {
            temp = s[n - i - 1];
            s[n - i - 1] = s[i];
            s[i] = temp;
        }
        
        if(x < 0)
        {
            s = "-" + s;
        }
        
        // convert string to integer
        try 
        {
            return stoi(s) ;
        }
        catch(out_of_range) 
        { 
            return 0;
        }
    }
};