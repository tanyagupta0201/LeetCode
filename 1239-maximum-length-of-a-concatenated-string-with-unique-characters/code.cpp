class Solution
{
public:
    int dfs(vector<string> &arr, string str, int idx)
    {
        unordered_set<char> s(str.begin(), str.end());

        if (s.size() != str.size())
            return 0;

        int len = str.length();

        for (int i = idx; i < arr.size(); i++)
        {
            len = max(len, dfs(arr, str + arr[i], i + 1));
        }

        return len;
    }

    int maxLength(vector<string> &arr)
    {
        return dfs(arr, "", 0);
    }
};