// As the array is already sorted we know can track the count of each number by going to next second element to it.
// And replace it whenever there is count > 2 and increase k value for both appending and traversal.

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 0;
        
        for (int n : nums)
        {
             if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        }
        
        return i; 
    }
};