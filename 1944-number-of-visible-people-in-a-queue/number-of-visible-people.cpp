class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> ans(n, 0);
        stack<int> st;

        // find next greater element to the right
        for (int i = n - 1; i >= 0; i--)
        {
            int visible = 0; // counts the number of people visible

            while (!st.empty() && heights[i] > st.top())
            {
                visible++; // as the people of lesser heights will be visible
                st.pop();
            }

            // If stack is not empty then i_th person can see one more person which is taller than himself.
            // so, increase by 1
            if (!st.empty())
                visible++;

            ans[i] = visible;

            st.push(heights[i]);
        }

        return ans;
    }
};