class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row)
    {
        int l = 0, r = matrix[0].size() - 1;
        
        while(l <= r)
        {
            int mid = r + (l - r) / 2;
            
            if(matrix[row][mid] == target)
            {
                return true;
            }
            else if(matrix[row][mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        } 
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // Perform Binary Search on each row
        for(int i = 0; i < matrix.size(); i++)
        {
            if(binarySearch(matrix, target, i))
                return true;
        }
        
        return false;
    }
};