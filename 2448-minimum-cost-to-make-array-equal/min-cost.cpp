class Solution
{
public:
    static bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.first <= p2.first;
    }
    long long minCost(vector<int> &num, vector<int> &cst)
    {

        vector<pair<int, int>> v;

        for (int i = 0; i < num.size(); i++)
        {
            v.push_back({num[i], cst[i]});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> nums, cost;

        for (int i = 0; i < num.size(); i++)
        {
            nums.push_back(v[i].first);
            cost.push_back(v[i].second);
        }

        long long n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            n += cost[i];
        }

        long long x = n / 2 + 1; // (+ 1 as it corrects for 1 indexing)
        long long y = 0;
        int prev = nums[0];
        int target = -1;

        for (int i = 0; i < nums.size(); i++)
        {

            y += cost[i];
            if (y >= x)
            {
                target = nums[i];
                break;
            }
        }

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += abs((long long)nums[i] - (long long)target) * (long long)cost[i];
        }

        return ans;
    }
};