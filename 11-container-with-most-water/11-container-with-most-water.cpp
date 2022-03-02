// https://youtu.be/ZHQg07n_tbg

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = 0;
        int minHeight;
        
        int n = height.size();
        int left = 0, right = n - 1;
        
        while(left < right)
        {
            minHeight = min(height[right], height[left]);
            maxArea = max(maxArea, (right - left) * minHeight);
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxArea;
    }
};