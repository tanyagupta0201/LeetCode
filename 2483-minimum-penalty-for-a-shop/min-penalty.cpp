/*
Here, the idea is to store the number of 'Y' and 'N' in a vector, let's call them vector y and n;
At any instance i the penalty depend on the sum of number of 'Y' remaining and the number of 'N' passed.
So, for that we'll be calculating the suffix sum of 'Y' and prefix sum of 'N' and storing them on vector y and n respectively. Then for each index the ans becomes
y[i]+n[i], and taking the minimum of all the indeces gives us the answer!
We'll be pushing 0 to y at end because at last no 'Y' will be left and similarly we'll do that for 'N' at initial stage as no 'N' have been passed.
*/

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();

        vector<int> yes, no;
        yes.push_back(0);
        no.push_back(0);

        int c = 0;

        // calculate prefix sum of NO
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'N')
            {
                c++;
            }
            no.push_back(c);
        }

        // calculate suffix sum of YES
        c = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (customers[i] == 'Y')
            {
                c++;
            }
            yes.push_back(c);
        }

        reverse(yes.begin(), yes.end());

        int ans = INT_MAX;
        int idx = 0;
        for (int i = 0; i < n + 1; i++)
        {
            int hr = yes[i] + no[i];

            if (hr < ans)
            {
                idx = i; // min index at which the shop should close
                ans = hr;
            }
        }

        return idx;
    }
};