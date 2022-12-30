/*
    1) The town judge trusts nobody => outdegree should be 0
    2) Everybody (except for the town judge) trusts the town judge => indegree should be (n - 1)
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);

        for (auto it : trust)
        {
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};