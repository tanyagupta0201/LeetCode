class Solution {
public:
    string generateTheString(int n) 
    {
        string ans = "";
        
        if(n % 2 != 0)
        {
            while(n--)
            {
                ans += "a";
            }
        }
        else
        {
            ans += "b";
            n--;
            while(n--)
            {
                ans += "a";
            }
        }
        
        return ans;
    }
};