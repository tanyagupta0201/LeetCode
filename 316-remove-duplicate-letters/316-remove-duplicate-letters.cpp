/*
   If lexicographic order is not asked
   
// Make a visited array and mark all the positions as 0
// Check for every character one by one
// If this character is occuring for the first time 
// Add it to the result and mark its position as 1 in the visited array

class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.size();
        bool vis[256] = {0};
        
        string res;
        
        for(int i = 0; i < n; i++)
        {
            if(vis[s[i]] == 0)
            {
                vis[s[i]] = 1;
                res += s[i];
            }
        }
        cout << res;
        sort(res.begin(), res.end());
        return res;
    }
};

*/

/*
    1. Initialize an string res for storing smallest lexicographical order.
    2. Store the frequency of each character present in the given string in an vector cnt.
    3. Maintain an vector vis for making the characters that are already present in resultant string res.
    4. Traverse the given string s and for each character s[i] perform the following operation.
    5. Decrease the frequency of the current character by 1.
    6. If the current character is not mark as visited in the vector vis, then perform following,
    7. If the last letter of res is less than s[i], add s[i] to res.
    8. If the last letter of res is greater than s[i] and the cnt of the last letter of res exceeds 0, then remove that character        & mark vis[s[i]] as 0 and continue this step till above condition satisfies.
    9. After breaking out from above condition , add s[i] to res & mark vis[s[i]] as 1.
    10. return res.

*/

class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> freq(26);
        vector<int> vis(26);
        
        string res = "";
        
        for(auto it : s)
            freq[it - 'a']++;
        
        for(auto it : s)
        {
            freq[it - 'a']--;
            
            // If the character is not visited already
            if(!vis[it - 'a'])
            {
                // Since we need to return ans in smallest lexicographic order
                while(!res.empty() && res.back() > it && freq[res.back() - 'a'] > 0)
                {
                    vis[res.back() - 'a'] = false;
                    res.pop_back();
                }
                
                vis[it - 'a'] = true;
                res += it;
            }
                
        }
        
        return res;
    }
};