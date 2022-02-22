class Solution {
public:
    string remove(string s)
    {
        stack<char> st;
        string x;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '#')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            x.push_back(st.top());
            st.pop();                
        }
        
        return x;
    }
    
    bool backspaceCompare(string s, string t) 
    {
        return(remove(s) == remove(t));        
    }
};