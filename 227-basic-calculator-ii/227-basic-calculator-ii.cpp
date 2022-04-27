class Solution {
public:
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '*' || ch == '-' || ch == '/';
    }
    
    int calculate(string s) 
    {
        stack<int> st;
        
        int num = 0;
        char sign = '+';
        
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            
            if(isOperator(s[i]) || i == s.length() - 1)
            {
                if(sign == '+')
                {
                    st.push(num);
                }
                
                else if(sign == '-')
                {
                    st.push(-num);
                }
                
                else if(sign == '*')
                {
                    int k = st.top();
                    st.pop();
                    st.push(k * num);
                }
                
                else if(sign == '/')
                {
                    int k = st.top();
                    st.pop();
                    st.push(k / num);
                }
                
                num = 0;
                sign = s[i];
            }
        }
        
        int res = 0;
        
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};