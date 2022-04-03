class Solution {
public:
    long long numberOfWays(string s) 
    {
        long long ans = 0;
        int n = s.size();
        
        vector<int> zero(n, 0), one(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                zero[i] = s[i] == '0' ? 1 : 0; // Agar 0 hai toh hume number of 1 calculate karne hai
                one[i] = s[i] == '1' ? 1 : 0;  // Agar 1 hai toh hume number of 0 calculate karne hai
            }
            else
            {
                zero[i] = zero[i - 1] + (s[i] == '0');
                one[i] = one[i - 1] + (s[i] == '1');
            }
        }
        
        for(int i = 1; i < n - 1; i++) // first aur last element ke liye thodi na dekhna hai
        {
            if(s[i] == '1')
            {
                long long x = zero[i - 1];           // number of 0 on left side
                long long y = zero[n - 1] - zero[i]; // number of 0 on right side
                
                ans += (x * y);
            }
            else
            {
                long long x = one[i - 1];           // number of 1 on left side
                long long y = one[n - 1] - one[i];  // number of 1 on right side
                
                ans += (x * y);
            }
        }
        
        return ans;
    }
};