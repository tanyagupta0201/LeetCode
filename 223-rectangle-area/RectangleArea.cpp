// https://leetcode.com/problems/rectangle-area/solutions/2822392/explanation-with-comments-java-cpp-totalarea-overlappedarea-easy-solution/

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        // Calculate the area of both the rectangles
        int ar1 = (ax2 - ax1) * (ay2 - ay1);
        int ar2 = (bx2 - bx1) * (by2 - by1);

        int totalArea = ar1 + ar2;

        // calculate all the four boundaries

        int leftBoundary = max(ax1, bx1);
        int rightBoundary = min(ax2, bx2);

        int upperBoundary = min(by2, ay2);
        int lowerBoundary = max(ay1, by1);

        // now if both the rectangles overlap, we need to subtract the common area
        if (rightBoundary > leftBoundary && upperBoundary > lowerBoundary)
        {
            int commonArea = (rightBoundary - leftBoundary) * (upperBoundary - lowerBoundary);
            totalArea = totalArea - commonArea;
        }

        return totalArea;
    }
};