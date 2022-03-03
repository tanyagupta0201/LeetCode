/* O(n ^ 2)
    
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < n - 1; i++)
        {
            int diff = nums[i + 1] - nums[i]; // difference between 1st 2 elements
            
            for(int j = i + 2; j < n; j++) // We will start from 3rd element
            {
                if(nums[j] - nums[j - 1] == diff)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
*/


/*
   O(n) solution

   The Idea is Simple , the array is called arithmetic if it consists of at least 3 elements.
   So, firstly if arr_size is < 3 , we will return false.
   The second requirement of the question is, that the difference b/w any two consecutive elements should be same.
   Storing diff of first 2 elements in diff as prev_diff = nums[1] - nums[0].
   Now iterating a loop from i = 1 to nums.size()-1 and finding the diff of next consecutive elements.
   If the diff is equal to prev_diff, increase the cnt of ind variable;
   else set ind to zero and update prev_diff with curr diff.
   add ind to cnt.
   Return cnt.
*/

class Solution {
public:     
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        int cnt = 0, diff = 0 , ind = 0;
        int prev_diff = nums[1] - nums[0];
        
        for(int i = 1; i<nums.size()-1 ; ++i)
        {
            // curr difference
            int diff = nums[i+1] - nums[i];
            
            // if we find same diff of consecutive elements
            // increase count
            if(diff ==  prev_diff)
                ++ind;
            
            else
            {
                // update prev diff with curr diff
                // as we don't find consecutive elements with same diff
                prev_diff = diff;
                ind = 0;  // make ind to 0
            }
            
            // add cosecutive arithmetic sequence cnt
            cnt += ind;
        }
               
        return cnt;
    }
};

