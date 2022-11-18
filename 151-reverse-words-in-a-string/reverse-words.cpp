class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int n = s.size();

        string res = "";

        // We need to remove extra spaces as well
        while (i < n)
        {
            while (i < n && s[i] == ' ')
            {
                i++;
            }

            if (i >= n)
            {
                break;
            }

            int j = i + 1;

            while (j < n && s[j] != ' ')
            {
                j++;
            }

            string sub = s.substr(i, j - i);
            if (res.size() == 0)
            {
                res = sub;
            }
            else
            {
                res = sub + " " + res;
            }

            i = j + 1;
        }

        return res;
    }
};