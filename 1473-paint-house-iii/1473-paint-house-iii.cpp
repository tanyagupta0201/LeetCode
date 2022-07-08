// explanation: https://leetcode.com/problems/paint-house-iii/discuss/2252875/EASIEST-DP-GUARANTEE-Beginner-Friendly

int n;
vector<int> houses;
vector<vector<int>> cost;
vector<vector<vector<int>>> dp;
int c;

int rec(int i, int last, int target)
{
    // Pruning
    if (target < 0)
        return -1; // we cant make negative target, also we can't access dp[][][-veTarget] so prune it initially.

    // cout<<"Checking Base case : "<<endl;
    // base case
    if (i == n && target != 0)
    { // it can be so that we have not made required targets.
        return -1;
    }
    if (i == n && target == 0)
    {
        return 0;
    }

    // cache check
    // cout<<"Checking Cache : "<<endl;

    if (dp[i][last][target] != -2)
    {
        return dp[i][last][target];
    }
    // cout<<"Cache not found"<<endl;

    int ans = INT_MAX;     // keeping answer as INT_MAX because we will take minimum with possible answer.
    bool possible = false; // No color is possible till now

    // cout<<"Checking if house already colored "<<endl;
    if (houses[i] != 0)
    {
        if (houses[i] != last)
        {
            return dp[i][last][target] = rec(i + 1, houses[i], target - 1);
        }
        else
        {
            return dp[i][last][target] = rec(i + 1, houses[i], target);
        }
    }
    // cout<<"House Not colored last summer"<<endl;

    // cout<<"Trying all colors : "<<endl;
    for (int k = 0; k < c; k++)
    {
        // choice of color is k+1
        // index is k
        // cout<<"Trying color : "<<k+1<<endl;
        int temp;
        if (k + 1 != last)
        {
            temp = rec(i + 1, k + 1, target - 1);
        }
        else
        {
            temp = rec(i + 1, k + 1, target);
        }
        // if this color is possible
        if (temp != -1)
        {
            // cout<<k+1<<" color is possible"<<endl;
            possible = true;
            ans = min(ans, cost[i][k] + temp);
        }
    }
    if (possible)
    {
        return dp[i][last][target] = ans;
    }
    else
    { // no possible color found for this place, as we need to color all houses, => answer is -1.
        return dp[i][last][target] = -1;
    }
}

class Solution
{
public:
    int minCost(vector<int> &house, vector<vector<int>> &cst, int r, int col, int target)
    {
        cost = cst;
        houses = house;
        c = col;
        n = r;
        dp.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            dp[i].resize(n + 1);
            for (int j = 0; j <= n; j++)
            {
                dp[i][j].resize(target + 1);
                for (int k = 0; k <= target; k++)
                {
                    dp[i][j][k] = -2;
                }
            }
        }
        // dp.resize(m+1 , vector<vector<int>>(n+1 , vector<int>(target+1 , -2));
        //  cout<<"initialised: "<<endl;
        return rec(0, 0, target); // hope nobody acceses -1 index in dp
        // return -1;
    }
};