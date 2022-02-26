// https://youtu.be/qC5DGX0CPFA

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        int ans = 0;
        
        stack<int> st; // Index Stack
        st.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                    st.pop();
                
                if(!st.empty())
                    ans = max(ans, i - st.top());
                else
                    st.push(i);   
            }
        }
        return ans;   
    }
};