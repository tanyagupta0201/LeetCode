class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        map<int, long long> m;

        // edges = [1,0,0,0,0,7,7,5]

        // 0->0, 1->0, 5->0, 7->0
        for (int i = 0; i < edges.size(); i++)
        {
            m[edges[i]] = 0;
        }

        // 0->10, 1->0, 5->7, 7->11
        for (int i = 0; i < edges.size(); i++)
        {
            m[edges[i]] += i;
        }

        int maxi = 0;
        int idx = -1;

        for (auto it : m)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
                idx = it.first;
            }
        }

        return idx;
    }
};