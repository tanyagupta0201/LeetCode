class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> st; // We will store the indices of the brackets as that index needs to be deleted from the string
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        
        // Now delete the indices present in the stack from the original string
        while(!st.empty())
        {
            s.erase(st.top(), 1); // deletes 1 character from st.top()
            st.pop();
        }
        
        return s;
    }
};