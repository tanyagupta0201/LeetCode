/*
    Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.
    Then use the formula min(prefix[i],suffix[i])-arr[i] to compute water trapped at each index.
    
    Time Complexity: O(3*N) as we are traversing through the array only once. 
    And O(2*N) for computing prefix and suffix array.

    Space Complexity:O(N)+O(N) for prefix and suffix arrays.

*/

class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        
        maxLeft[0] = height[0];
        
        for(int i = 1; i < n; i++)
        {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        
        maxRight[n - 1] = height[n - 1];
        
        for(int i = n - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        
        vector<int> water(n);
        
        for(int i = 0; i < n; i++)
        {
            water[i] = min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        int totalWater = 0;
        
        for(int i = 0; i < n; i++)
        {
            totalWater += water[i];
        }
        
        return totalWater;
    }
};