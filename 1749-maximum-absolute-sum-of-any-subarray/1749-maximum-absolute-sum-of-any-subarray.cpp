class Solution {
public:
    // Modified Kadanes Algorithm
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int box1 = 0; // Keeps track of positive elements
        int box2 = 0; // Keeps track of negative elements
        int ans = 0;
        
        for(auto it: nums)
        {
            box1 += it;
            box2 += it;
            
            ans = max({ans, box1, abs(box2)});
            
            if(box1 < 0)
                box1 = 0;
            
            if(box2 > 0)
                box2 = 0;
        }
        
        return ans;
    }
};