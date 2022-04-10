class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> st;
        
        for(auto i : ops)
        {
            if(i == "C")
            {
                st.pop();
            }
            else if(i == "D")
            {
                st.push(st.top() * 2);
            }
            else if(i == "+")
            {
                int x = st.top();
                st.pop();
                
                int y = st.top();
                
                st.push(x);
                st.push(x + y);
            }
            else
            {
                st.push(stoi(i));
            }
        }
        
        // Find sum of all scores
        int ans = 0;
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;        
    }
};