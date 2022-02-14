class Solution {
public:
    void helper(int index, string s, vector<string> &ans)
    {
        if(index == s.size())
        {
            ans.push_back(s);
            return;
        }
        
        if(s[index] >= 97 && s[index] <= 122)
        {
            s[index] = toupper(s[index]);
            helper(index + 1, s, ans);
            s[index] = tolower(s[index]);
        }
        else if(s[index] >= 65 && s[index] <= 90)
        {
            s[index] = tolower(s[index]);
            helper(index + 1, s, ans);
            s[index] = toupper(s[index]);            
        }
        
        // Incase its not an alphabet
        helper(index + 1, s, ans);
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> ans;
        helper(0, s, ans);
        return ans;
    }
};