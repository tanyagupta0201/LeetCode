// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        stack<long long> st;
        vector<long long> v(n);
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.size() > 0)
            {
                while(st.size() > 0 && st.top() <= arr[i])
                {
                    st.pop();
                }
            }
            
            if(st.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends