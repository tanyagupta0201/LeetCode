class Solution {
public:
    // Increasing attack, decreasing defence
    static bool cmp(vector<int> &v1, vector<int> &v2)
    {
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        
        return v1[0] < v2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), cmp);
        
        int ans = 0;
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top() < arr[i][1])
            {
                ans++;
                st.pop();
            }
            
            st.push(arr[i][1]);
        }
        
        return ans;
    }
};