class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=1;
        for(int i=0; i<n; i++)
        {
            unordered_set<int> st;
            int count=0;
            for(int j=i; j<n; j++)
            {
                if(st.find(s[j])==st.end())
                {
                    if(j==n-1)
                    {
                        count++;
                        ans=max(ans,count);
                        break;
                    }
                    count++;
                    st.insert(s[j]);
                }
                else
                {
                    ans=max(ans,count);
                    break;
                }
            }
        }
        return ans;
    }
};
