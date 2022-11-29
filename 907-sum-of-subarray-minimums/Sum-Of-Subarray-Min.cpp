class Solution
{
public:
    long long M = 1e9 + 7;

    vector<int> nearest_smaller_to_left(vector<int> &vt, int n)
    {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                ans.push_back(-1);
            else
            {
                while (st.empty() == false && vt[st.top()] > vt[i])
                    st.pop();

                if (st.empty() == false)
                    ans.push_back(st.top());
                else
                    ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nearest_smaller_to_right(vector<int> &vt, int n)
    {
        stack<int> st;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(n);
            else
            {
                while (st.empty() == false && vt[st.top()] >= vt[i])
                    st.pop();

                if (st.empty() == false)
                    ans.push_back(st.top());
                else
                    ans.push_back(n);
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> smaller_left = nearest_smaller_to_left(arr, n);
        vector<int> smaller_right = nearest_smaller_to_right(arr, n);

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long prod = ((i - smaller_left[i]) * (smaller_right[i] - i)) % M;
            prod = (prod * arr[i]) % M;
            ans += prod;
            ans %= M;
        }
        return ans;
    }
};
