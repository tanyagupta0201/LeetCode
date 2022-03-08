class Solution {
public:
    // For 2 points to be in a straight line, they should have same slope

    // To check slope condition: 
    // (y2-y1)/(x2-x1) == (y3-y2)/(x3-x2)
    // If the ques contains duplicates values, it would become (y-y)/(x-x) = 0/0
    // 0/0 problem will arise
    // To avoid this we can rewrite the equation as: 
    // (y2-y1)(x3-x2) = (y3-y2)(x2-x1)  -> We can check this condition incase there are duplicate points
    // This way is better than division approach
    
    // This ques does not have duplicate points 
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int points = coordinates.size(); // To find number of points
        
        // For first 2 points, we would find x diff and y diff
        int xdiff = coordinates[1][0] - coordinates[0][0];
        int ydiff = coordinates[1][1] - coordinates[0][1];
        
        int curr_xdiff, curr_ydiff;
        
        for(int i = 2; i < points; i++) // i = 2 means 3rd point
        {
            int curr_xdiff = coordinates[i][0] - coordinates[i - 1][0];
            int curr_ydiff = coordinates[i][1] - coordinates[i - 1][1];
            
            if(ydiff * curr_xdiff != xdiff * curr_ydiff) // this means they do not form straight line
                return false;
        }

        return true;        
    }
};