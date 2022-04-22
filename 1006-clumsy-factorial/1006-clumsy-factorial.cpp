class Solution {
public:
    int clumsy(int n) 
    {
        stack<int> st;
        st.push(n);
        n--;
        int i = 0;
        
        while(n >= 1)
        {
            if(i % 4 == 0)
            {
                int k = st.top();
                st.pop();
                st.push(k * n);
            
                i++;
                n--;
            }
            
            else if(i % 4 == 1)
            {
                int k = st.top();
                st.pop();
                st.push(k / n);
                
                i++;
                n--; 
            }
            
            else if(i % 4 == 2)
            {
                st.push(n);
                i++;
                n--;
            }
            
            else
            {
                st.push(-n);
                i++;
                n--;
            }
        }
        
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};