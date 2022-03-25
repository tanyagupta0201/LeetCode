/*
    Input: costs = [[10,20],[30,200],[400,50],[30,20]]
    Output: 110
    Compute the cost of sending every person to City A.
    The cost will be 10 + 30 + 400 + 30 = 470
    Compute the difference if a Person is sent to City B
    D1 -> 20 - 10 = 10
    D2 -> 200 - 30 = 170
    D3 -> 50 - 400 = -350
    D4 -> 20 - 30 = -10
    If the last two persons are sent to City B instead of City A, you can save maximum, as those are the persons costing more 
    to City A.
    Sort the diff.
    D3, D4, D1, D2
    Now pick N persons which has least diff and send them to City B.
    Add the diff cost to the total
    470 + (-350) + -(10) = 110
    return cost.
    
    https://youtu.be/vtNoP43hGJA

*/




class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] - a[0] > b[1] - b[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int n = costs.size();
        
        sort(costs.begin(), costs.end(), comparator);
        
        int minCost = 0;
        for(int i = 0; i < n; i++)
        {
            minCost += i >= n/2 ? costs[i][1] : costs[i][0];
        }
        
        return minCost;
    }
};