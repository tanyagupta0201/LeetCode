/*

The idea behind this approach is to carefully observe what is being asked in the question.

It is given for i < j < k
we need to check if there exists arr[i] < arr[k] < arr[j]
Now for the k index element we need previous element greater than it and minimum element less than it
So all we need to do is just maintain a stack with top element being the greatest and a minimum element
*/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> st; // We make a stack to store elements in monotonic decreasing order and also store minimum value

        int currMin = nums[0]; // to store the min element

        for (int i = 1; i < nums.size(); i++) // traversing the given vector from index 1 as index 0 is already concidered in currMin
        {
            while (!st.empty() && nums[i] >= st.top().first) // keep removing all greater and equal elements
                st.pop();
            if (!st.empty() && nums[i] > st.top().second) // and if the stack still non-empty this means that our current element is less
                                                          // than the top of the stack , So now we check if this element is greater than the minimum value in the stack
                return true;                              // if condition satisfies return true
            st.push({nums[i], currMin});                  // push current element and previous minimum
            currMin = min(currMin, nums[i]);              // update the minimum element
        }
        return false; // If the condition never became true it means we shall return false
    }
};