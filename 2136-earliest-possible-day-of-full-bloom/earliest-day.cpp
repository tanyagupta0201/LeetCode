class Solution
{
public:
    // first we will plant the flower seed that will have max growing time

    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < plantTime.size(); i++)
        {
            v.push_back({growTime[i], plantTime[i]});
        }

        // sort the vector in non-increasing order
        // to get grow time of plants in descending order
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int start = 0;
        int ans = 0;

        for (int i = 0; i < plantTime.size(); i++)
        {
            start += v[i].second;               // adding plant time
            ans = max(ans, start + v[i].first); // total time to bloom = plantTime + growTime
        }

        return ans;
    }
};