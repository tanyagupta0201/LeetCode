/*
   STEPS:
   Loop i on all numbers,
   loop j on all numbers,
   check if k = target - i - j is valid.
   We have to keep in mind the 3 cases to cover all the possibility of the combination.

   i == j == k
   i == j != k
   i < k && j < k
   
*/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        unordered_map<int, long> mp;
        
        for(auto it: arr)
            mp[it]++;
        
        long res = 0;
        int mod = 1e9 + 7;
        
        for(auto i : mp)
        {
            for(auto j : mp)
            {
                int n1 = i.first, n2 = j.first, n3 = target - n1 - n2;
                
                if(!mp.count(n3))
                    continue;
                
                // Case 1
                if(n1 == n2 && n2 == n3)
                {
                    res += mp[n1] * (mp[n1] - 1) * (mp[n1] - 2) / 6;
                }
                
                // Case 2
                else if(n1 == n2 && n2 != n3)
                {
                    res += mp[n1] * (mp[n1] - 1) / 2 * mp[n3];
                }
                
                // Case 3
                else if(n1 < n2 && n2 < n3)
                {
                    res += mp[n1] * mp[n2] * mp[n3];
                }
            }
        }
        
        return res % mod;
        
    }
};