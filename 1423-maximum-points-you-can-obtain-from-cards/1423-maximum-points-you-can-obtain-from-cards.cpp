class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size(), sum = 0;
        
        if (k > n)
            return 0;
        
        for (auto x : cardPoints)
            sum += x;
        
        k = n - k; // size of removing sub array
        
        if (k == 0)
            return sum;
        
        int curr = 0, start = 0, ans = INT_MIN;
        
        for (int i = 0; i < n; i += 1)
        {
            curr += cardPoints[i];
            
            if (i >= k - 1)
            {
                ans = max(ans, sum - curr);
                curr -= cardPoints[start++];
            }
        }
        
        return ans;
    }
};