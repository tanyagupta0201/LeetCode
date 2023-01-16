//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        // Your code here
        vector<long long> ans(n);
        stack<long long > s;
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[i] >= s.top())
                s.pop();
                
            if (!s.empty())
                ans[i] = s.top();
            else
                ans[i] = -1;
                
            s.push(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

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
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends