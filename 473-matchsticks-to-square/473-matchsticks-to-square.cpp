//https://leetcode.com/problems/matchsticks-to-square/discuss/1274063/Matchsticks-to-Square-or-Solution-With-ExplanationOptimisations.

class Solution {
    public:
    bool vis[16];
    bool canMakeSquare(vector<int> &matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 0)
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        for (int i = idx; i < size(matchsticks); i++)
        {
            if (!vis[i])
            {
                if (currentSum + matchsticks[i] <= oneSideLength) 
                {
                    vis[i] = true;
                    if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }

    bool makesquare(vector < int > & matchsticks)
    {
        memset(vis, false, sizeof(vis));
    
        int sum = 0;
        
        for (int i: matchsticks)
            sum += i;
        
        if (sum % 4)
            return false;
        
        int oneSideLength = sum / 4;
        int totalSides = 4;
        
        return canMakeSquare(matchsticks, 0, oneSideLength, totalSides);
    }
};