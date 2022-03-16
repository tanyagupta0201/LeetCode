/*
    1. If the element X has been pushed to the stack then check if the top element in the pop[] sequence is X or not.
    2. If it is X then pop it right now else top of the push[] sequence will be changed and make the sequences invalid.
    3. Similarly, do the same for all the elements and check if the stack is empty or not in the last.
    4. If empty then print True else print False.
    5. Time Complexity O(N)
    6. Space Complexity O(N)
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int j = 0;
        
        for(int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            
            while(!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
};