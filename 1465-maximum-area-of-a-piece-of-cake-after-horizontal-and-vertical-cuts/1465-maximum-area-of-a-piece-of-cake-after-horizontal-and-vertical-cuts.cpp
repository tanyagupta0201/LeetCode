class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti)
    {
        sort(hori.begin(), hori.end());
        sort(verti.begin(), verti.end());
        
        long long maxH = hori[0] - 0;
        long long maxV = verti[0] - 0;
        
        for(int i = 1; i < hori.size(); i++)
        {
            long long diff = hori[i] - hori[i - 1];
            maxH = max(maxH, diff);
        }
        
        for(int i = 1; i < verti.size(); i++)
        {
            long long diff = verti[i] - verti[i - 1];
            maxV = max(maxV, diff);
        }
        
        // edge case(last value)
        maxH = max((long long) h - hori[hori.size() - 1], maxH);
        maxV = max((long long) w - verti[verti.size() - 1], maxV);
        
        return (maxH * maxV) % 1000000007;
    }
};