// Problem Link: https://leetcode.com/problems/keyboard-row/

class Solution
{
public:
    bool isSubset(unordered_set<char> ws, unordered_set<char> s)
    {
        for (auto x : ws)
        {
            if (!s.count(x))
                return false;
        }
        return true;
    }

    vector<string> findWords(vector<string> &words)
    {
        string line1 = "qwertyuiop";
        string line2 = "asdfghjkl";
        string line3 = "zxcvbnm";

        unordered_set<char> s1{line1.begin(), line1.end()};
        unordered_set<char> s2{line2.begin(), line2.end()};
        unordered_set<char> s3{line3.begin(), line3.end()};

        vector<string> ans;

        for (auto &w : words)
        {
            unordered_set<char> ws;

            for (auto x : w)
            {
                ws.insert(tolower(x));
            }

            if (isSubset(ws, s1) || isSubset(ws, s2) || isSubset(ws, s3))
                ans.push_back(w);
        }
        return ans;
    }
};
