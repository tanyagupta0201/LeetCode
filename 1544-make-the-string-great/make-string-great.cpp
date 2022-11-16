class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && s[i] != st.top() && (s[i] == toupper(st.top()) || st.top() == toupper(s[i])))
                st.pop();
            else
                st.push(s[i]);
        }

        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};