// https://youtu.be/3QJzHqNAEXs

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();

        // Final string will be stored in the stack
        stack<char> s;

        for (char ch : num)
        {
            while (!s.empty() && k > 0 && s.top() > ch)
            {
                s.pop();
                k--;
            }

            if (!s.empty() || ch != '0')
            {
                s.push(ch);
            }
        }

        // Corner case
        // If there is no peak element
        // eg: 1, 2, 3 and k = 2
        // So, remove the largest 2 elements ie. from the end
        while (!s.empty() && k--)
        {
            s.pop();
        }

        if (s.empty())
        {
            return "0";
        }

        // Now retrive the number from the stack into a string(reusing num)
        while (!s.empty())
        {
            num[n - 1] = s.top();
            s.pop();
            n--;
        }

        return num.substr(n);
    }
};