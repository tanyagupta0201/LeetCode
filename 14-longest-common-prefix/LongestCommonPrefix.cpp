/*
    When Strings are sorted, the possibility of characters to be least
    common is between 1st and last member of the sorted strings.

*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        int n = strs.size();

        sort(strs.begin(), strs.end());

        string a = strs[0];
        string b = strs[n - 1];

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                res += a[i];
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
