/*
    1) looks like graph ques solved with bfs or dfs BUT IT IS NOT !!
    2) if we want to go from row 1 to row 5 we need to cover row 2,3,4 we cannot skip any of them
       same thing goes for columns
    3) we need to add of all the rows and col we cross
*/

class Solution
{
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
    {
        int cost = 0;

        // We need to determine in which direction we want to go, forward or backward

        // for row
        if (startPos[0] <= homePos[0]) // forward direction
        {
            // start point ki next row se add karna hai na
            for (int i = startPos[0] + 1; i <= homePos[0]; i++)
            {
                cost += rowCosts[i];
            }
        }
        else
        {
            // start point ke prev row se add karna hai na
            for (int i = startPos[0] - 1; i >= homePos[0]; i--)
            {
                cost += rowCosts[i];
            }
        }

        // for col
        if (startPos[1] <= homePos[1])
        {
            // start point ki next col se add karna hai na
            for (int i = startPos[1] + 1; i <= homePos[1]; i++)
            {
                cost += colCosts[i];
            }
        }
        else
        {
            // start point ki prev col se add karna hai na
            for (int i = startPos[1] - 1; i >= homePos[1]; i--)
            {
                cost += colCosts[i];
            }
        }

        return cost;
    }
};